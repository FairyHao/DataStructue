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
{             //�������飨�ڽӾ��󣩱�ʾ������������ͼ
	char v1,v2;
	int i,j;
	cout<<"���붥������";
	cin>>vexnum;
	cout<<"���������";
	cin>>arcnum;
	cout<<"���붥�㣺";
	for(int i=0;i<vexnum;i++)
		cin>>vexs[i];
	for(int i=0;i<vexnum;i++)  //��ʼ���ڽӾ���
		for(int j=0;j<vexnum;j++)
			arcs[i][j].adj=0;

	for(int k=0;k<arcnum;k++) //�����ڽӾ���
	{
		cout<<"����һ���������Ķ��㣺";
		cin>>v1>>v2;
		i=LocateVex(v1);  //ȷ�� v1,v2��ͼ�е�λ��
		j=LocateVex(v2);
		arcs[i][j].adj=1; 
		arcs[j][i].adj=1;
	}

}


int Graph::Judge_Pass_MGraph()
{           //�ж�һ���ڽӾ���洢������ͼ�ǲ��ǿɴ��ݵ�,���򷵻�1,���򷵻�0

	for(int x=0;x<vexnum;x++)
		for(int y=0;y<vexnum;y++)
			if(arcs[x][y].adj)
			{
				for(int z=0;z<vexnum;z++)
					if(z!=x&&arcs[y][z].adj&&!arcs[x][z].adj) 
						return 0;//ͼ���ɴ��ݵ�����
			}
			return 1;
}