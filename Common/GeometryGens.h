#ifndef _GEOMETRY_GENS_H_
#define _GEOMETRY_GENS_H_

#include <Windows.h>
#include <xnamath.h>
#include <vector>
#include "AppUtil.h"
namespace GeoGen
{
	
	//����һ��ͨ�õĶ���ṹ��λ�á����ߡ����ߡ���������
	struct Vertex
	{
		Vertex(){}
		Vertex(const XMFLOAT3 _pos, XMFLOAT3 _normal, XMFLOAT3 _tangent, XMFLOAT2 _tex):
			pos(_pos),normal(_normal),tangent(_tangent),tex(_tex){}

		XMFLOAT3	pos;
		XMFLOAT3	normal;
		XMFLOAT3	tangent;
		XMFLOAT2	tex;
		XMFLOAT2    detailTex;
	};

	//��������ṹ�����㼯��+��������
	struct MeshData
	{
		std::vector<Vertex>	vertices;
		std::vector<UINT>	indices;
	};

	void CreateLODLevel(std::vector<std::vector<std::vector<UINT>>>  &IndicesLOD,UINT n,UINT m,int MAX_LEVEL);
	void CreateMeshLOD(float width,float height,UINT m,UINT n,int MAX_LEVEL,MeshData &mesh);
	//����һ��������ӣ�ָ���ܿ��(X����)���ܸ߶�(Z����); m��nΪ���߷����ϵĸ�������
	void CreateGrid(float width, float height, UINT m, UINT n,int MAX_LEVEL, MeshData &mesh);
};


#endif