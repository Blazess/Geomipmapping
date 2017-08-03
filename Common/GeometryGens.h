#ifndef _GEOMETRY_GENS_H_
#define _GEOMETRY_GENS_H_

#include <Windows.h>
#include <xnamath.h>
#include <vector>
#include "AppUtil.h"
namespace GeoGen
{
	
	//定义一个通用的顶点结构：位置、法线、切线、纹理坐标
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

	//基本网络结构：顶点集合+索引集合
	struct MeshData
	{
		std::vector<Vertex>	vertices;
		std::vector<UINT>	indices;
	};

	void CreateLODLevel(std::vector<std::vector<std::vector<UINT>>>  &IndicesLOD,UINT n,UINT m,int MAX_LEVEL);
	void CreateMeshLOD(float width,float height,UINT m,UINT n,int MAX_LEVEL,MeshData &mesh);
	//创建一个网络格子：指定总宽度(X方向)、总高度(Z方向); m、n为宽、高方向上的格子数量
	void CreateGrid(float width, float height, UINT m, UINT n,int MAX_LEVEL, MeshData &mesh);
};


#endif