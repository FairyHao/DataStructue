#pragma once


const int MAX_VERTEX_NUM=20;

struct ArcNode  //表结点
{
	int adjvex;        //该弧所指向的顶点的位置
	ArcNode* nextarc;  //指向下一条弧的指针
};


struct VNode  //头结点
{ 
	char data;           //顶点信息
	ArcNode *firstarc;   //指向第一条依附该顶点的弧的指针
};

class DGraph
{
public:
	VNode vexs[MAX_VERTEX_NUM];
	int vexnum,arcnum; //图的当前顶点数和弧数
public:
	DGraph(void);
	~DGraph(void);
	int LocateVex(char);
	void Build_AdjList();
	void OutPutArc();
	void InsertVex();
	void DeleteVex(char v);
	void InsertArc();
	void DeleteArc();
};
