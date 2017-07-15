#include "StdAfx.h"
#include "DGraph.h"
#include "iostream"
using namespace std;

DGraph::DGraph(void)
{
}

DGraph::~DGraph(void)
{
}


int DGraph::LocateVex(char c){
	int i;
	for (i=0;i<vexnum;i++)
	{
		if(vexs[i].data==c)
			return i;
	}
}

void DGraph::Build_AdjList(){
	char *ch;
	char t,h;
	int i,j;
	ArcNode *p=NULL;
	cout<<"输入顶点数：";
	cin>>vexnum;
	if(vexnum<0){
		cout<<"error!";
		return;
	}
	cout<<"输入边数：";
	cin>>arcnum;
	if (arcnum<0)
	{
		cout<<"error!";
		return;
	}
	ch=new char[vexnum];
	cout<<"输入各顶点的符号：";
	cin>>ch;
	for (int m=0;m<vexnum;m++)
	{
		vexs[m].data=ch[m];
		vexs[m].firstarc=NULL;
	}
	for (int m=0;m<arcnum;m++)
	{
		cout<<"输入弧：";
		cin>>ch;
		t=ch[0];
		h=ch[1];
		i=LocateVex(t);
		j=LocateVex(h);
		if (i<0||j<0)
		{
			cout<<"error!";
			return;
		}
		p=new ArcNode;
		ArcNode *q=NULL;
		if(!vexs[i].firstarc)
			vexs[i].firstarc=p;
		else{
			for (q=vexs[i].firstarc;q->nextarc;q=q->nextarc)
			q->nextarc=p;
		}
		p->adjvex=j;
		p->nextarc=NULL;
	}

}

void DGraph::OutPutArc(){
	int j;
	ArcNode *p=NULL;
	for(int i=0;i<vexnum;i++)
	{
		p=vexs[i].firstarc;
		while(p)
		{
			j=p->adjvex;
			cout<<" <"<<vexs[i].data<<","<<vexs[j].data<<" >";
			p=p->nextarc;
		}
		cout<<endl;
	}
}

void DGraph::InsertVex(){
	char v;
	cout<<"输入要插入的顶点：";
	cin>>v;
	vexnum++;
	vexs[vexnum-1].data=v;
	vexs[vexnum-1].firstarc=NULL;
}

void DGraph::DeleteVex(char v){
	//在邻接表表示的图G上删除顶点v	
	int m;
	VNode t;
	for(m=0;m<vexnum;m++)
		if(vexs[m].data==v)
			break;
	//将各顶点连接 v 的边删除
	ArcNode* p=NULL;
	ArcNode* q=NULL;
	for(int i=0;i<vexnum;i++)
	{
		if(i!=m)
			for(p=vexs[i].firstarc;p;p=p->nextarc)
			{
				if(p->adjvex==m)
				{
					if(p==vexs[i].firstarc)
						vexs[i].firstarc=p->nextarc;
					else 
					{
						for(q=vexs[i].firstarc;q->nextarc!=p;q=q->nextarc);
						q->nextarc=p->nextarc;
					}
				}
			}
}
	//将待删除顶点交换到最后一个顶点
	t.data=vexs[m].data;
	t.firstarc=vexs[m].firstarc; 
	vexs[m].data=vexs[vexnum-1].data;
	vexs[m].firstarc=vexs[vexnum-1].firstarc;
	vexs[vexnum-1].data=t.data;
	vexs[vexnum-1].firstarc=t.firstarc;

	vexnum--;
}


void DGraph::InsertArc(){
	//在邻接表表示的图上插入边<v1,v2>
	char v1,v2;
	int i,j;
	ArcNode* p=NULL;
	ArcNode* q=NULL;
	cout<<"输入要插入的边所对应的顶点：";
	cin>>v1>>v2;
	i=LocateVex(v1);
	j=LocateVex(v2);
	if(i<0 || j<0)
	{
		cout<<"ERROR!";
		return;
	}
	//新建立边
	q=new ArcNode;
	q->adjvex=j;
	q->nextarc=NULL;
	//将边插入邻接表
	if(!vexs[i].firstarc) 
		vexs[i].firstarc=q;
	else 
	{
		p=vexs[i].firstarc;
		while(p->nextarc)
			p=p->nextarc;
		p->nextarc=q;
	}

	arcnum++;
}

void DGraph::DeleteArc()
{           //在邻接表表示的图G上删除边<v1,v2>
	char v1,v2;
	int i,j;
	cout<<"输入要删除的边所对应的顶点：";
	cin>>v1>>v2;
	i=LocateVex(v1);
	j=LocateVex(v2);
	if(i<0 || j<0)
	{
		cout<<"ERROR!";
		return;
	}
	ArcNode* p=NULL;
	ArcNode* q=NULL;
	for(p=vexs[i].firstarc;p;p=p->nextarc)
	{
		if(p->adjvex==j)
		{
			if(vexs[i].firstarc->adjvex==j)
				vexs[i].firstarc=p->nextarc;
			else
			{
				for(q=vexs[i].firstarc;q->nextarc!=p;q=q->nextarc);
				q->nextarc=p->nextarc;
			}
		}
	}
	arcnum--;
}