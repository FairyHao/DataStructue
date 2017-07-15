// 7-14.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#define MAX_VERTEX_NUM 10
typedef enum { DG, DN, UDG, UDN } GraphKind;
typedef struct ArcNode//Arc:��
{
	int adjvex;//adj:adjacency:�ڽӣ�ver:vertex:���㡣
	struct ArcNode *nextarcl;//��һ����
}ArcNode;
typedef struct VNode
{
	char data;//���趥������Ϊchar���ͣ���ʵ����һ�㲻�Ǹ����ӵ����ͣ�
	ArcNode *firstarc;
}Vnode, AdjList[MAX_VERTEX_NUM];
typedef struct
{
	AdjList vertices;
	int vernum, arcnum;
	GraphKind kind;
}ALGraph;

ALGraph* createALGraph()
{
	int verNum=6, arcNum=3;
	char VNodeArray[] = { '1', '2', '3', '4', '5', '6' };
	ALGraph *ag = (ALGraph*)malloc(sizeof(ALGraph));
	ag->kind = DG;
	ag->vernum = verNum;
	ag->arcnum = arcNum;
	for (int i = 0; i < verNum;i++)
	{
		Vnode *vn = (Vnode*)malloc(sizeof(Vnode));
		vn->data = VNodeArray[i];
		vn->firstarc = NULL;
		ag->vertices[i] = *vn;
	}
	char v1, v2;
	for (int i = 0; i < arcNum; i++)
	{
		ArcNode *arc = (ArcNode*)malloc(sizeof(ArcNode));
		cin >> v1;
		cin >> v2; 
		int x;
		int y;
		for (int j = 0; j < verNum; j++)
		{
			if (v1 == ag->vertices[j].data)
			{
				x = j;
			}
			if (v2 == ag->vertices[j].data)
			{
				y = j;
			}
		}
		arc->adjvex = y;
		arc->nextarcl = NULL;
		ArcNode *p = ag->vertices[x].firstarc;
		if (!p)
		{
			ag->vertices[x].firstarc = arc;
		}
		else
		{
			while (p->nextarcl)
			{
				p = p->nextarcl;
			}
			p->nextarcl = arc;
		}
	}
 	return ag;
}


int _tmain(int argc, _TCHAR* argv[])
{
	ALGraph *ag = createALGraph();
//	int i = ag->vernum;
	cout << "test";
	while (1)
	{
	}
	return 0;
}

