#include "StdAfx.h"
#include "Graph.h"
#include "iostream"
using namespace std;

Graph::Graph(void)
{
}

Graph::~Graph(void)
{
}

int Graph::LocateVex(char c)
{
	int i;
	for(i=0;i<vexnum;i++)
	{
		if(vexs[i]==c)
			return i;
	}
}



void Graph::CreateGraph()
{             //采用数组（邻接矩阵）表示法，构造无向图
	char v1,v2;
	int i,j;
	cout<<"输入顶点数：";
	cin>>vexnum;
	cout<<"输入边数：";
	cin>>arcnum;
	cout<<"输入顶点：";
	for(int i=0;i<vexnum;i++)
		cin>>vexs[i];
	for(int i=0;i<vexnum;i++)  //初始化邻接矩阵
		for(int j=0;j<vexnum;j++)
			arcs[i][j].adj=0;

	for(int k=0;k<arcnum;k++) //构造邻接矩阵
	{
		cout<<"输入一条边依附的顶点：";
		cin>>v1>>v2;
		i=LocateVex(v1);  //确定 v1,v2在图中的位置
		j=LocateVex(v2);
		arcs[i][j].adj=1; 
		arcs[j][i].adj=1;
	}

}


int Graph::Judge_Pass_MGraph()
{           //判断一个邻接矩阵存储的无向图是不是可传递的,是则返回1,否则返回0

	for(int x=0;x<vexnum;x++)
		for(int y=0;y<vexnum;y++)
			if(arcs[x][y].adj)
			{
				for(int z=0;z<vexnum;z++)
					if(z!=x&&arcs[y][z].adj&&!arcs[x][z].adj) 
						return 0;//图不可传递的条件
			}
			return 1;
}