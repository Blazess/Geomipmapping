#include "Light.fx"
#include "PerlinNoise.fx"
//��Ե��������Effectȫ�ֱ���
cbuffer PerObject
{
	float4x4	g_worldViewProj;		//���硢�ӽǡ�ͶӰ�任
	float4x4	g_worldInvTranspose;	//����任���桢ת�þ���
	float4x4	g_world;				//����任
};

//���ÿһ֡��Effectȫ�ֱ���
cbuffer PerFrame
{
	DirLight	g_dirLight;
	Material	g_material;
	float3		g_eyePos;
};

float1       g_M;
float1       g_N;
//����
Texture2D g_tex;
Texture2D g_terrainTex;
Texture2D g_detailTex;
//���ù���
SamplerState samTex
{
	Filter = MIN_MAG_MIP_LINEAR;
	AddressU = Wrap;  
    AddressV =  Wrap;
};
SamplerState samTex2
{
	Filter = MIN_MAG_MIP_LINEAR;
};
//���붥����Ϣ��λ�����ꡢ���ߡ���������
struct VertexIn
{
	float3	pos:	POSITION;
	float3	normal:	NORMAL;
	float2	tex:	TEXCOORD0;
	float2  detailtex: TEXCOORD1;
};

//���������Ϣ
struct VertexOut
{
	float4	posH:	SV_POSITION;	//ͶӰ������
	float3	pos:	POSITION;		//����任������
	float3	normal:	NORMAL;			//����任����
	float2	tex:	TEXCOORD0;		//��������
	float2  detailtex: TEXCOORD1;
};

VertexOut VS(VertexIn vin)
{
	float scale = (g_M+g_N)/10;
	float normaloffset = 0.01;
	VertexOut vout;
	//int level = ceil((abs(vin.tex.x-0.5)+abs(vin.tex.y-0.5))/0.2);
	float4 offset = g_tex.SampleLevel(samTex2, vin.tex, 0);
	//vin.pos.y = offset.r*100;
	//vin.pos.y = (offset.r*0.7+offset2.r*0.3)*20;
	
	vin.pos.y = (offset.r+offset.g+offset.b)/3*scale;

	//vin.pos.y = 0;

	vout.posH = mul(float4(vin.pos,1.f),g_worldViewProj);
	vout.pos = mul(float4(vin.pos,1.f),g_worldViewProj).xyz;

	float2 btex = float2(vin.tex.x,vin.tex.y+normaloffset);
	float2 ctex = float2(vin.tex.x+normaloffset,vin.tex.y);
	float4 b = g_tex.SampleLevel(samTex2, btex,0);
	float4 c = g_tex.SampleLevel(samTex2, ctex,0);
	float by = (b.r+b.g+b.b)/3*scale;
	float cy = (c.r+c.g+c.b)/3*scale;
	float3 bpos = float3(vin.pos.x,by,vin.pos.z+normaloffset*g_M);
	float3 cpos = float3(vin.pos.x+normaloffset*g_N,cy,vin.pos.z);
	float3 ab = bpos-vin.pos;
	float3 ac = cpos-vin.pos;
	vin.normal = cross(ac,ab);

	
			
	vin.normal = normalize(vin.normal);

	//vin.normal += float3(PerlinNoise(vin.normal.x),PerlinNoise(vin.normal.y),PerlinNoise(vin.normal.z));
	vout.normal = vin.normal;
	//vout.normal = float3(1.0,1.0,1.0);
	//vout.normal = mul(vin.normal,(float3x3)g_worldInvTranspose);

	vout.tex = vin.tex;
	vout.detailtex = vin.detailtex;
	return vout;
}

float4 PS(VertexOut pin, uniform bool useLight): SV_TARGET
{
	float4 ambient = {1.f,1.f,1.f,1.f};
	float4 diffuse = {0.f,0.f,0.f,0.f};
	float4 spec = {0.f,0.f,0.f,0.f};

	float3 toEye = g_eyePos - pin.pos;  
	float   dist = length(toEye);  
	//���ʹ�ù���
	if(useLight)
	{

		float3 normal = pin.normal;
		toEye = normalize( g_eyePos- pin.pos);

		ComputeDirLight(g_material,g_dirLight,normal,toEye,ambient,diffuse,spec);
	}

	float4 detail = g_detailTex.Sample(samTex,pin.detailtex);
	//float4 texColor = float4(1,1,1,1);
	float4 texColor = g_terrainTex.Sample(samTex,pin.tex);
	//����*(������+������⣩+ȫ����⣬����������ɫ
	float4 finalColor =  2*(detail+texColor-0.5) * (ambient+diffuse+spec);
	//float4 finalColor = texColor* (ambient+diffuse)+spec;

	if(useLight)
	{
		float4 g_fogColor = float4(0.8,0.8,0.8,0);
		float fogFactor = saturate((dist - 800)/((g_N+g_M)));  
		finalColor = lerp(finalColor,g_fogColor,fogFactor);  
		finalColor = saturate(finalColor);
	}
	//finalColor = float4(1.0,1.0,1.0,1.0);
	return finalColor;
}

//ʹ�ù��յ�technique
technique11 TexLight
{
	pass P0
	{
		SetVertexShader( CompileShader(vs_5_0,VS()) );
		SetPixelShader( CompileShader(ps_5_0,PS(true)) );
	}
}

//��ʹ�ù��յ�technique
technique11 Tex
{
	pass P0
	{
		SetVertexShader( CompileShader(vs_5_0,VS()) );
		SetPixelShader( CompileShader(ps_5_0,PS(false)) );
	}
}