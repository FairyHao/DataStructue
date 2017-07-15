#include "StdAfx.h"
#include "UDGraph.h"
#include "iostream"
using namespace std;

UDGraph::UDGraph(void)
{
}

UDGraph::~UDGraph(void)
{
}


int UDGraph::LocateVex(char c){
	int i;
	for(i=0;i<vexnum;i++)
	{
		if(adjmulist[i].data==c)
			return i;
	}
}

void UDGraph::CreateUDG()
{ /* 采用邻接多重表存储结构,构造无向图G */
	int i,j,k;
	char va,vb;
	EBox *p;
	char *ch;
	cout<<"输入顶点数:";
	cin>>vexnum;
	if(vexnum<0) 
	{
		cout<<"ERROR"; //顶点数不能为负
		return;
	}
	cout<<"输入边数：";
	cin>>edgenum;
	if(edgenum<0) 
	{
		cout<<"ERROR"; //边数不能为负
		return;
	}
	ch=new char[vexnum];
	cout<<"输入各顶点的符号:";
	cin>>ch;
	for(int m=0;m<vexnum;m++)
	{
		adjmulist[m].data=ch[m]; /* 构造顶点向量 */
		adjmulist[m].firstedge=NULL;
	}
	cout<<"请顺序输入每条边的两个端点:\n";
	for(k=0;k<edgenum;k++) /* 构造表结点链表 */
	{
		cin>>ch;
		va=ch[0];
		vb=ch[1];
		i=LocateVex(va); /* 一端 */
		j=LocateVex(vb); /* 另一端 */
		p=new EBox;
		p->mark=0; /* 设初值 */
		p->ivex=i;
		p->jvex=j;
		p->ilink=adjmulist[i].firstedge; /* 插在表头 */
		adjmulist[i].firstedge=p;
		p->jlink=adjmulist[j].firstedge; /* 插在表头 */
		adjmulist[j].firstedge=p;
	}
	return;
}


void UDGraph::InsertVex()
{ /* 初始条件: 无向图G存在,v和G中顶点有相同特征 */
	/* 操作结果: 在G中增添新顶点v(不增添与顶点相关的弧,留待InsertArc()去做) */
	char v;
	cout<<"输入要插入的顶点";
	cin>>v;
	adjmulist[vexnum].data=v;
	adjmulist[vexnum].firstedge=NULL;
	vexnum++;
}

void UDGraph::DeleteVex(char v)
{ /* 初始条件: 无向图G存在,v是G中某个顶点 */
	/* 操作结果: 删除G中顶点v及其相关的边 */
	int i,j;
	char w;
	EBox *p;
	i=LocateVex(v); /* i为待删除顶点的序号 */
	if(i<0)
		return;
	for(j=0;j<vexnum;j++) /* 删除与顶点v相连的边(如果有的话) */
	{
		if(j==i)
			continue;
		w=adjmulist[j].data; /* w是第j个顶点的值 */
		DeleteArc(v,w);
	}
	for(j=i+1;j<vexnum;j++) /* 排在顶点v后面的顶点的序号减1 */
		adjmulist[j-1]=adjmulist[j];
	vexnum--; /* 顶点数减1 */
	for(j=i;j<vexnum;j++) /* 修改顶点的序号 */
	{
		p=adjmulist[j].firstedge;
		if(p)
		{
			if(p->ivex==j+1)
			{
				p->ivex--;
				p=p->ilink;
			}
			else
			{
				p->jvex--;
				p=p->jlink;
			}
		}
	}
	return;
}

void UDGraph::DeleteArc(char v,char w)
{ /* 初始条件: 无向图G存在,v和w是G中两个顶点 */
	/* 操作结果: 在G中删除弧<v,w> */
	int i,j;
	EBox *p,*q;
	i=LocateVex(v);
	j=LocateVex(w);
	if(i<0||j<0||i==j)
		return;  /* 图中没有该点或弧 */
	/* 以下使指向待删除边的第1个指针绕过这条边 */
	p=adjmulist[i].firstedge; /* p指向顶点v的第1条边 */
	if(p&&p->jvex==j) /* 第1条边即为待删除边(情况1) */
		adjmulist[i].firstedge=p->ilink;
	else if(p&&p->ivex==j) /* 第1条边即为待删除边(情况2) */
		adjmulist[i].firstedge=p->jlink;
	else /* 第1条边不是待删除边 */
	{
		while(p) /* 向后查找弧<v,w> */
		{
			if(p->ivex==i&&p->jvex!=j) /* 不是待删除边 */
			{
				q=p;
				p=p->ilink; /* 找下一个邻接顶点 */
			}
			else if(p->jvex==i&&p->ivex!=j) /* 不是待删除边 */
			{
				q=p;
				p=p->jlink; /* 找下一个邻接顶点 */
			}
			else /* 是邻接顶点w */
				break;
		}
		if(!p) /* 没找到该边 */
			return;
		if(p->ivex==i&&p->jvex==j) /* 找到弧<v,w>(情况1) */
			if(q->ivex==i)
				q->ilink=p->ilink;
			else
				q->jlink=p->ilink;
		else if(p->ivex==j&&p->jvex==i) /* 找到弧<v,w>(情况2) */
			if(q->ivex==i)
				q->ilink=p->jlink;
			else
				q->jlink=p->jlink;
	}
	/* 以下由另一顶点起找待删除边且删除之 */
	p=adjmulist[j].firstedge; /* p指向顶点w的第1条边 */
	if(p->jvex==i) /* 第1条边即为待删除边(情况1) */
	{
		adjmulist[j].firstedge=p->ilink;
		free(p);
	}
	else if(p->ivex==i) /* 第1条边即为待删除边(情况2) */
	{
		adjmulist[j].firstedge=p->jlink;
		free(p);
	}
	else /* 第1条边不是待删除边 */
	{
		while(p) /* 向后查找弧<v,w> */
			if(p->ivex==j&&p->jvex!=i) /* 不是待删除边 */
			{
				q=p;
				p=p->ilink; /* 找下一个邻接顶点 */
			}
			else if(p->jvex==j&&p->ivex!=i) /* 不是待删除边 */
			{
				q=p;
				p=p->jlink; /* 找下一个邻接顶点 */
			}
			else /* 是邻接顶点v */
				break;
			if(p->ivex==i&&p->jvex==j) /* 找到弧<v,w>(情况1) */
			{
				if(q->ivex==j)
					q->ilink=p->jlink;
				else
					q->jlink=p->jlink;
				free(p);
			}
			else if(p->ivex==j&&p->jvex==i) /* 找到弧<v,w>(情况2) */
			{
				if(q->ivex==j)
					q->ilink=p->ilink;
				else
					q->jlink=p->ilink;
				free(p);
			}
	}
	edgenum--;
	return;
}


void UDGraph::InsertArc(char v,char w)
{ /* 初始条件: 无向图G存在,v和W是G中两个顶点 */
	/* 操作结果: 在G中增添弧<v,w> */
	int i,j;
	EBox *p;
	i=LocateVex(v); /* 一端 */
	j=LocateVex(w); /* 另一端 */
	if(i<0||j<0)
		return;
	p=new EBox;
	p->mark=0;
	p->ivex=i;
	p->jvex=j;
	p->ilink=adjmulist[i].firstedge; /* 插在表头 */
	adjmulist[i].firstedge=p;
	p->jlink=adjmulist[j].firstedge; /* 插在表头 */
	adjmulist[j].firstedge=p;
	edgenum++;
	return;
}

void UDGraph::Display()
{ /* 输出无向图的邻接多重表G */
	int i;
	EBox *p;
	for(i=0;i<vexnum;i++)
	{
		p=adjmulist[i].firstedge;
		while(p)
			if(p->ivex==i) /* 边的i端与该顶点有关 */
			{
				if(!p->mark) /* 只输出一次 */
				{
					cout<<'<'<<adjmulist[i].data<<','<<adjmulist[p->jvex].data<<'>'<<endl;
					p->mark=1;
				}
				p=p->ilink;
			}
			else /* 边的j端与该顶点有关 */
			{
				if(!p->mark) /* 只输出一次 */
				{
					cout<<'<'<<adjmulist[p->ivex].data<<','<<adjmulist[i].data<<'>'<<endl;
					p->mark=1;
				}
				p=p->jlink;
			}
			cout<<endl;
	}
}