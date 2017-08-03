#include "GeometryGens.h"
namespace GeoGen
{
	void CreateLODLevel(std::vector<std::vector<std::vector<UINT>>>  &IndicesLOD,UINT n,UINT m,int MAX_LEVEL)
	{
		int level0num[16] = {24,21,21,18,21,18,18,15,21,18,18,15,18,15,15,12};
		int level0[16][24][2] = {
			0,0, 0,1, 1,0, 0,1, 1,1, 1,0, 0,1, 0,2, 1,1, 0,2, 1,2, 1,1, 1,0, 1,1, 2,0, 1,1, 2,1, 2,0, 1,1, 1,2, 2,1, 1,2, 2,2, 2,1,
			0,0, 0,1, 1,0, 0,1, 1,1, 1,0, 1,0, 1,1, 2,0, 1,1, 1,2, 2,2, 0,1, 0,2, 1,1, 0,2, 1,2, 1,1, 1,1, 2,2, 2,0, 0,0, 0,0, 0,0,
			0,0, 0,1, 1,0, 0,1, 1,1, 1,0, 1,0, 1,1, 2,0, 1,1, 2,2, 2,1, 0,1, 0,2, 1,1, 0,2, 2,2, 1,1, 1,1, 2,1, 2,0, 0,0, 0,0, 0,0,
			0,0, 0,1, 1,0, 0,1, 0,2, 1,1, 0,2, 2,2, 1,1, 0,1, 1,1, 1,0, 1,0, 1,1, 2,0, 1,1, 2,2, 2,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0,  
			0,0, 0,1, 1,1, 0,2, 1,2, 1,1, 1,1, 2,1, 2,0, 1,2, 2,2, 2,1, 0,1, 0,2, 1,1, 0,0, 1,1, 2,0, 1,1, 1,2, 2,1, 0,0, 0,0, 0,0,
			0,0, 0,1, 1,1, 0,1, 0,2, 1,1, 1,1, 1,2, 2,2, 0,0, 1,1, 2,0, 0,2, 1,2, 1,1, 1,1, 2,2, 2,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0,  
			0,0, 0,1, 1,1, 0,1, 0,2, 1,1, 1,1, 2,2, 2,1, 0,0, 1,1, 2,0, 1,1, 2,1, 2,0, 0,2, 2,2, 1,1, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0,  
			0,0, 0,1, 1,1, 0,0, 1,1, 2,0, 0,2, 2,2, 1,1, 0,1, 0,2, 1,1, 1,1, 2,2, 2,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0,     
			0,0, 0,2, 1,1, 0,2, 1,2, 1,1, 1,1, 2,1, 2,0, 1,2, 2,2, 2,1, 0,0, 1,1, 1,0, 1,0, 1,1, 2,0, 1,1, 1,2, 2,1, 0,0, 0,0, 0,0,
			0,0, 1,1, 1,0, 0,0, 0,2, 1,1, 1,1, 2,2, 2,0, 0,2, 1,2, 1,1, 1,0, 1,1, 2,0, 1,1, 1,2, 2,2, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0,
			0,0, 0,2, 1,1, 1,0, 1,1, 2,0, 1,1, 2,2, 2,1, 0,0, 1,1, 1,0, 1,1, 2,1, 2,0, 0,2, 2,2, 1,1, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0,
			0,0, 0,2, 1,1, 1,0, 1,1, 2,0, 0,2, 2,2, 1,1, 0,0, 1,1, 1,0, 1,1, 2,2, 2,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0,   
			0,0, 0,2, 1,1, 0,2, 1,2, 1,1, 1,1, 1,2, 2,1, 0,0, 1,1, 2,0, 1,1, 2,1, 2,0, 1,2, 2,2, 2,1, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0,
			0,0, 0,2, 1,1, 0,2, 1,2, 1,1, 1,1, 2,2, 2,0, 0,0, 1,1, 2,0, 1,1, 1,2, 2,2, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0,
			0,0, 0,2, 1,1, 0,2, 2,2, 1,1, 1,1, 2,2, 2,1, 0,0, 1,1, 2,0, 1,1, 2,1, 2,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0,
			0,0, 0,2, 1,1, 0,0, 1,1, 2,0, 0,2, 2,2, 1,1, 1,1, 2,2, 2,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0,         
		};
		int corner[16][18][2] = {
			0,0 ,0,2, 1,1, 0,2, 1,2, 1,1, 0,0, 1,1, 2,0, 1,1, 2,1, 2,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0,
			0,0, 0,2, 1,1, 0,2, 1,2, 1,1, 0,0, 1,1, 1,0, 1,0, 1,1, 2,0, 1,1, 2,1, 2,0, 0,0, 0,0, 0,0,
			0,0, 0,1, 1,1, 0,1, 0,2, 1,1, 0,2, 1,2, 1,1, 0,0, 1,1, 2,0, 1,1, 2,1, 2,0, 0,0, 0,0, 0,0,
			0,0, 0,1, 1,0, 0,1, 1,1, 1,0, 0,1, 0,2, 1,1, 0,2, 1,2, 1,1, 1,0, 1,1, 2,0, 1,1, 2,1, 2,0,

			0,0, 1,1, 1,0, 0,0, 0,2, 1,1, 0,2, 2,2, 1,1, 1,1, 2,2, 2,1, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0,
			0,0, 1,1, 1,0, 0,0, 0,2, 1,1, 0,2, 1,2, 1,1, 1,1, 1,2, 2,1, 1,2, 2,2, 2,1, 0,0, 0,0, 0,0,
			0,0, 0,1, 1,0, 0,1, 1,1, 1,0, 0,1, 0,2, 1,1, 0,2, 2,2, 1,1, 1,1, 2,2, 2,1, 0,0, 0,0, 0,0,
			0,0, 0,1, 1,0, 0,1, 1,1, 1,0, 0,1, 0,2, 1,1, 0,2, 1,2, 1,1, 1,1, 1,2, 2,1, 1,2, 2,2, 2,1,

			0,0, 0,1, 1,1, 1,1, 2,2, 2,0, 0,0, 1,1, 2,0, 1,1, 1,2, 2,2, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0,
			0,0, 0,1, 1,1, 0,0, 1,1, 2,0, 1,1, 2,1, 2,0, 1,1, 1,2, 2,1, 1,2, 2,2, 2,1, 0,0, 0,0, 0,0,
			0,0, 0,1, 1,0, 0,1, 1,1, 1,0, 1,0, 1,1, 2,0, 1,1, 2,2, 2,0, 1,1, 1,2, 2,2, 0,0, 0,0, 0,0,
			0,0, 0,1, 1,0, 0,1, 1,1, 1,0, 1,0, 1,1, 2,0, 1,1, 2,1, 2,0, 1,1, 1,2, 2,1, 1,2, 2,2, 2,1,

			0,1, 0,2, 1,1, 0,2, 2,2, 1,1, 1,0, 1,1, 2,0, 1,1, 2,2, 2,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0,
			0,1, 0,2, 1,1, 1,0, 1,1, 2,0, 0,2, 2,2, 1,1, 1,1, 2,1, 2,0, 1,1, 2,2, 2,1, 0,0, 0,0, 0,0,
			0,1, 0,2, 1,1, 0,2, 1,2, 1,1, 1,0, 1,1, 2,0, 1,1, 2,2, 2,0, 1,1, 1,2, 2,2, 0,0, 0,0, 0,0,
			0,1, 0,2, 1,1, 0,2, 1,2, 1,1, 1,0, 1,1, 2,0, 1,1, 2,1, 2,0, 1,1, 1,2, 2,1, 1,2, 2,2, 2,1
		};
		IndicesLOD.resize(16);
		bool s[4];
		for (int m = 0;m<16;m++)
		{
			s[3] = m>>3&1;s[2] = m>>2&1;s[1] = m>>1&1;s[0] = m&1;
			IndicesLOD[m].resize(MAX_LEVEL);
			int base = n*pow(2,MAX_LEVEL-1)+1;
			int cSize = pow(2,MAX_LEVEL-1);
			for (int level = MAX_LEVEL-1;level>=0;level--)
			{
				UINT jump = pow(2,(MAX_LEVEL-level-1));
				if (level == 0)
				{
					IndicesLOD[m][level].push_back(0);
					IndicesLOD[m][level].push_back(jump);
					IndicesLOD[m][level].push_back(jump*base);
					IndicesLOD[m][level].push_back(jump);
					IndicesLOD[m][level].push_back(jump*base+jump);
					IndicesLOD[m][level].push_back(jump*base);
					continue;
				}
				if(level == 1)
				{
					for (int i = 0;i<level0num[m];i++)
					{
						IndicesLOD[m][level].push_back(level0[m][i][0]*jump*base+level0[m][i][1]*jump);
					}
					continue;
				}
				for (int i = jump;i<cSize-jump;i+=jump)
					for (int j = jump;j<cSize-jump;j+=jump)
					{
						IndicesLOD[m][level].push_back(i * base + j);
						IndicesLOD[m][level].push_back(i * base + j +jump);
						IndicesLOD[m][level].push_back((i+jump)*base+j);
						IndicesLOD[m][level].push_back(i * base + j + jump);
						IndicesLOD[m][level].push_back((i+jump)*base+j+jump);
						IndicesLOD[m][level].push_back((i+jump)*base+j);
					}
				if (level && s[3])//上边的修正
				{
					for (int  i = 2*jump;i<cSize-2*jump;i+=2*jump)
					{
						IndicesLOD[m][level].push_back(i);
						IndicesLOD[m][level].push_back(i+2*jump);
						IndicesLOD[m][level].push_back(i+jump+base*jump);
						IndicesLOD[m][level].push_back(i);
						IndicesLOD[m][level].push_back(i+jump+base*jump);
						IndicesLOD[m][level].push_back(i+base*jump);
						IndicesLOD[m][level].push_back(i+2*jump);
						IndicesLOD[m][level].push_back(i+2*jump+base*jump);
						IndicesLOD[m][level].push_back(i+jump+base*jump);
					}
				}
				else
				{
					for (int  i = 2*jump;i<int(cSize-2*jump);i+=jump)
					{
						IndicesLOD[m][level].push_back(i);
						IndicesLOD[m][level].push_back(i+jump);
						IndicesLOD[m][level].push_back(i+jump*base);
						IndicesLOD[m][level].push_back(i+jump);
						IndicesLOD[m][level].push_back(i+jump+jump*base);
						IndicesLOD[m][level].push_back(i+jump*base);
					}
				}
				if (level &&s[2])//左边的修正
				{
					for (int  i =2*jump*base;i<int(cSize*base-2*jump*base);i+=2*jump*base)
					{
						IndicesLOD[m][level].push_back(i);
						IndicesLOD[m][level].push_back(i+jump*base+jump);
						IndicesLOD[m][level].push_back(i+2*jump*base);
						IndicesLOD[m][level].push_back(i);
						IndicesLOD[m][level].push_back(i+jump);
						IndicesLOD[m][level].push_back(i+jump*base+jump);
						IndicesLOD[m][level].push_back(i+jump*base+jump);
						IndicesLOD[m][level].push_back(i+2*jump*base+jump);
						IndicesLOD[m][level].push_back(i+2*jump*base);
					}
				}
				else
				{
					for (int  i =2*jump*base;i<int(cSize*base-2*jump*base);i+=jump*base)
					{
						IndicesLOD[m][level].push_back(i);
						IndicesLOD[m][level].push_back(i+jump);
						IndicesLOD[m][level].push_back(i+jump*base);
						IndicesLOD[m][level].push_back(i+jump);
						IndicesLOD[m][level].push_back(i+jump*base+jump);
						IndicesLOD[m][level].push_back(i+jump*base);
					}
				}
				if (level &&s[1])//右边的修正
				{
					for (int  i = cSize-jump+2*jump*base;i<cSize*base+cSize-jump-2*jump*base;i+=2*jump*base)
					{
						IndicesLOD[m][level].push_back(i);
						IndicesLOD[m][level].push_back(i+jump);
						IndicesLOD[m][level].push_back(i+jump*base);
						IndicesLOD[m][level].push_back(i+jump);
						IndicesLOD[m][level].push_back(i+2*jump*base+jump);
						IndicesLOD[m][level].push_back(i+jump*base);
						IndicesLOD[m][level].push_back(i+jump*base);
						IndicesLOD[m][level].push_back(i+2*jump*base+jump);
						IndicesLOD[m][level].push_back(i+2*jump*base);
					}
				}
				else
				{
					for (int  i = cSize-jump+2*jump*base;i<int(cSize*base+cSize-jump-2*jump*base);i+=jump*base)
					{
						IndicesLOD[m][level].push_back(i);
						IndicesLOD[m][level].push_back(i+jump);
						IndicesLOD[m][level].push_back(i+jump*base);
						IndicesLOD[m][level].push_back(i+jump);
						IndicesLOD[m][level].push_back(i+jump*base+jump);
						IndicesLOD[m][level].push_back(i+jump*base);
					}
				}
				if (level && s[0])//下边的修正
				{
					for (int  i =  (cSize-jump)*base+2*jump;i<cSize+(cSize-jump)*base-2*jump;i+=2*jump)
					{
						IndicesLOD[m][level].push_back(i);
						IndicesLOD[m][level].push_back(i+jump);
						IndicesLOD[m][level].push_back(i+base*jump);
						IndicesLOD[m][level].push_back(i+jump);
						IndicesLOD[m][level].push_back(i+jump*2+base*jump);
						IndicesLOD[m][level].push_back(i+base*jump);
						IndicesLOD[m][level].push_back(i+jump);
						IndicesLOD[m][level].push_back(i+2*jump);
						IndicesLOD[m][level].push_back(i+2*jump+base*jump);
					}
				}
				else
				{
					for (int  i =  (cSize-jump)*base+2*jump;i<int(cSize+(cSize-jump)*base-2*jump);i+=jump)
					{
						IndicesLOD[m][level].push_back(i);
						IndicesLOD[m][level].push_back(i+jump);
						IndicesLOD[m][level].push_back(i+jump*base);
						IndicesLOD[m][level].push_back(i+jump);
						IndicesLOD[m][level].push_back(i+jump+jump*base);
						IndicesLOD[m][level].push_back(i+jump*base);
					}
				}
				//补角
				//左上角
				if (level && s[3] && s[2])
				{
					for (int i = 0;i<12;i++)
						IndicesLOD[m][level].push_back(corner[0][i][0]*jump*base+corner[0][i][1]*jump);
				}
				if (level && s[3] && !s[2])
				{
					for (int i = 0;i<15;i++)
						IndicesLOD[m][level].push_back(corner[1][i][0]*jump*base+corner[1][i][1]*jump);
				}
				if (level && !s[3] && s[2])
				{
					for (int i = 0;i<15;i++)
						IndicesLOD[m][level].push_back(corner[2][i][0]*jump*base+corner[2][i][1]*jump);
				}
				if (level && !s[3] && !s[2])
				{
					for (int i = 0;i<18;i++)
						IndicesLOD[m][level].push_back(corner[3][i][0]*jump*base+corner[3][i][1]*jump);
				}
				//右上角
				int baseru = cSize-2*jump;
				if (level && s[3] && s[1])
				{
					for (int i = 0;i<12;i++)
						IndicesLOD[m][level].push_back(baseru+corner[4][i][0]*jump*base+corner[4][i][1]*jump);
				}
				if (level && s[3] && !s[1])
				{
					for (int i = 0;i<15;i++)
						IndicesLOD[m][level].push_back(baseru+corner[5][i][0]*jump*base+corner[5][i][1]*jump);
				}
				if (level && !s[3] && s[1])
				{
					for (int i = 0;i<15;i++)
						IndicesLOD[m][level].push_back(baseru+corner[6][i][0]*jump*base+corner[6][i][1]*jump);
				}
				if (level && !s[3] && !s[1])
				{
					for (int i = 0;i<18;i++)
						IndicesLOD[m][level].push_back(baseru+corner[7][i][0]*jump*base+corner[7][i][1]*jump);
				}
				//左下角
				int baseld = cSize*base-2*jump*base;
				if (level && s[2] && s[0])
				{
					for (int i = 0;i<12;i++)
						IndicesLOD[m][level].push_back(baseld+corner[8][i][0]*jump*base+corner[8][i][1]*jump);
				}
				if (level && s[2] && !s[0])
				{
					for (int i = 0;i<15;i++)
						IndicesLOD[m][level].push_back(baseld+corner[9][i][0]*jump*base+corner[9][i][1]*jump);
				}
				if (level && !s[2] && s[0])
				{
					for (int i = 0;i<15;i++)
						IndicesLOD[m][level].push_back(baseld+corner[10][i][0]*jump*base+corner[10][i][1]*jump);
				}
				if (level && !s[2] && !s[0])
				{
					for (int i = 0;i<18;i++)
						IndicesLOD[m][level].push_back(baseld+corner[11][i][0]*jump*base+corner[11][i][1]*jump);
				}
				//右下角
				int baserd = cSize*base+cSize-2*jump-2*jump*base;
				if (level && s[1] && s[0])
				{
					for (int i = 0;i<12;i++)
						IndicesLOD[m][level].push_back(baserd+corner[12][i][0]*jump*base+corner[12][i][1]*jump);
				}
				if (level && s[1] && !s[0])
				{
					for (int i = 0;i<15;i++)
						IndicesLOD[m][level].push_back(baserd+corner[13][i][0]*jump*base+corner[13][i][1]*jump);
				}
				if (level && !s[1] && s[0])
				{
					for (int i = 0;i<15;i++)
						IndicesLOD[m][level].push_back(baserd+corner[14][i][0]*jump*base+corner[14][i][1]*jump);
				}
				if (level && !s[1] && !s[0])
				{
					for (int i = 0;i<18;i++)
						IndicesLOD[m][level].push_back(baserd+corner[15][i][0]*jump*base+corner[15][i][1]*jump);
				}
			}
		}
	}
	void CreateMeshLOD(float width,float height,UINT m,UINT n,int MAX_LEVEL,MeshData &mesh)
	{
		int chunkSize = pow(2,MAX_LEVEL-1);
		GeoGen::CreateGrid(width,height,m*chunkSize,n*chunkSize,MAX_LEVEL,mesh);
	}
	void CreateGrid(float width, float height, UINT m, UINT n,int MAX_LEVEL,MeshData &mesh)
	{
		mesh.vertices.clear();
		mesh.indices.clear();
		//每行顶点数、每列顶点数
		UINT nVertsRow = m + 1;
		UINT nVertsCol = n + 1;
		//起始x、z坐标
		float oX = -width * 0.5f;
		float oZ = height * 0.5f;
		//每一格纹理坐标变化
		float dx = width / m;
		float dz = height /n;

		//顶点总数量：nVertsRow * nVertsCol
		mesh.vertices.resize(nVertsRow * nVertsCol);

		//逐个添加顶点
		for(int i=0; i<nVertsCol; ++i)
		{
			float tmpZ = oZ - dz * i;
			for(int j=0; j<nVertsRow; ++j)
			{
				UINT index = nVertsRow * i + j;
				mesh.vertices[index].pos.x = oX + dx * j;
				mesh.vertices[index].pos.y = 0.f;
				mesh.vertices[index].pos.z = tmpZ;

				mesh.vertices[index].normal = mesh.vertices[index].pos;
				mesh.vertices[index].tangent = XMFLOAT3(1.f,0.f,0.f);
				
				mesh.vertices[index].tex = XMFLOAT2(dx*i/width,1-dz*j/height);
				mesh.vertices[index].detailTex = XMFLOAT2(dx*i/(width/50),dz*j/(height/50));
			}
		}

	}
};