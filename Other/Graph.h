#pragma once
#define MAX_VERTEX_NUM 20

struct ArcCell
{
	int adj;   //�����ϵ������Ȩͼ���� 1 �� 0��ʾ���ڷ�
	char *info; //�û������Ϣ��ָ��
};


class Graph
{
public:
	char vexs[MAX_VERTEX_NUM];  //��������
	ArcCell  arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; //�ڽӾ���
	int vexnum,arcnum; //ͼ�ĵ�ǰ�������ͻ���
public:
	Graph(void);
	~Graph(void);
	void CreateGraph();
	int  LocateVex(char c);
	int  Judge_Pass_MGraph();
};

