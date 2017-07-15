// 7-14.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#define MAX_VERTEX_NUM 10
typedef enum { DG, DN, UDG, UDN } GraphKind;
typedef struct ArcNode//Arc:弧
{
	int adjvex;//adj:adjacency:邻接；ver:vertex:顶点。
	struct ArcNode *nextarcl;//下一条弧
}ArcNode;
typedef struct VNode
{
	char data;//假设顶点类型为char类型，在实际中一般不是更复杂的类型；
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

