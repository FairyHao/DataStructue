#pragma once


const int MAX_VERTEX_NUM=20;

struct ArcNode  //����
{
	int adjvex;        //�û���ָ��Ķ����λ��
	ArcNode* nextarc;  //ָ����һ������ָ��
};


struct VNode  //ͷ���
{ 
	char data;           //������Ϣ
	ArcNode *firstarc;   //ָ���һ�������ö���Ļ���ָ��
};

class DGraph
{
public:
	VNode vexs[MAX_VERTEX_NUM];
	int vexnum,arcnum; //ͼ�ĵ�ǰ�������ͻ���
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
