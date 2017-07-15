#pragma once
#define MAX_VERTEX_NUM 20

struct EBox 
{
	int mark;
	int ivex,jvex;
	EBox *ilink,*jlink;
};

struct VexBox 
{
	char data;
	EBox *firstedge;
};

class UDGraph
{
public:
	VexBox adjmulist[MAX_VERTEX_NUM];
	int vexnum,edgenum;
public:
	UDGraph(void);
	~UDGraph(void);
	int LocateVex(char c);
	void CreateUDG();
	void Display();
	void InsertVex();
	void DeleteVex(char v);
	void InsertArc(char v,char w);
	void DeleteArc(char v,char w);
};

