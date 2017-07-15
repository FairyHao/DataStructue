#pragma once
#define MAX_VERTEX_NUM 20

struct ArcCell
{
	int adj;   //顶点关系，对无权图，用 1 或 0表示相邻否
	char *info; //该弧相关信息的指针
};


class Graph
{
public:
	char vexs[MAX_VERTEX_NUM];  //顶点向量
	ArcCell  arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; //邻接矩阵
	int vexnum,arcnum; //图的当前顶点数和弧数
public:
	Graph(void);
	~Graph(void);
	void CreateGraph();
	int  LocateVex(char c);
	int  Judge_Pass_MGraph();
};

