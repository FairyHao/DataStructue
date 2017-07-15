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
{ /* �����ڽӶ��ر�洢�ṹ,��������ͼG */
	int i,j,k;
	char va,vb;
	EBox *p;
	char *ch;
	cout<<"���붥����:";
	cin>>vexnum;
	if(vexnum<0) 
	{
		cout<<"ERROR"; //����������Ϊ��
		return;
	}
	cout<<"���������";
	cin>>edgenum;
	if(edgenum<0) 
	{
		cout<<"ERROR"; //��������Ϊ��
		return;
	}
	ch=new char[vexnum];
	cout<<"���������ķ���:";
	cin>>ch;
	for(int m=0;m<vexnum;m++)
	{
		adjmulist[m].data=ch[m]; /* ���춥������ */
		adjmulist[m].firstedge=NULL;
	}
	cout<<"��˳������ÿ���ߵ������˵�:\n";
	for(k=0;k<edgenum;k++) /* ����������� */
	{
		cin>>ch;
		va=ch[0];
		vb=ch[1];
		i=LocateVex(va); /* һ�� */
		j=LocateVex(vb); /* ��һ�� */
		p=new EBox;
		p->mark=0; /* ���ֵ */
		p->ivex=i;
		p->jvex=j;
		p->ilink=adjmulist[i].firstedge; /* ���ڱ�ͷ */
		adjmulist[i].firstedge=p;
		p->jlink=adjmulist[j].firstedge; /* ���ڱ�ͷ */
		adjmulist[j].firstedge=p;
	}
	return;
}


void UDGraph::InsertVex()
{ /* ��ʼ����: ����ͼG����,v��G�ж�������ͬ���� */
	/* �������: ��G�������¶���v(�������붥����صĻ�,����InsertArc()ȥ��) */
	char v;
	cout<<"����Ҫ����Ķ���";
	cin>>v;
	adjmulist[vexnum].data=v;
	adjmulist[vexnum].firstedge=NULL;
	vexnum++;
}

void UDGraph::DeleteVex(char v)
{ /* ��ʼ����: ����ͼG����,v��G��ĳ������ */
	/* �������: ɾ��G�ж���v������صı� */
	int i,j;
	char w;
	EBox *p;
	i=LocateVex(v); /* iΪ��ɾ���������� */
	if(i<0)
		return;
	for(j=0;j<vexnum;j++) /* ɾ���붥��v�����ı�(����еĻ�) */
	{
		if(j==i)
			continue;
		w=adjmulist[j].data; /* w�ǵ�j�������ֵ */
		DeleteArc(v,w);
	}
	for(j=i+1;j<vexnum;j++) /* ���ڶ���v����Ķ������ż�1 */
		adjmulist[j-1]=adjmulist[j];
	vexnum--; /* ��������1 */
	for(j=i;j<vexnum;j++) /* �޸Ķ������� */
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
{ /* ��ʼ����: ����ͼG����,v��w��G���������� */
	/* �������: ��G��ɾ����<v,w> */
	int i,j;
	EBox *p,*q;
	i=LocateVex(v);
	j=LocateVex(w);
	if(i<0||j<0||i==j)
		return;  /* ͼ��û�иõ�� */
	/* ����ʹָ���ɾ���ߵĵ�1��ָ���ƹ������� */
	p=adjmulist[i].firstedge; /* pָ�򶥵�v�ĵ�1���� */
	if(p&&p->jvex==j) /* ��1���߼�Ϊ��ɾ����(���1) */
		adjmulist[i].firstedge=p->ilink;
	else if(p&&p->ivex==j) /* ��1���߼�Ϊ��ɾ����(���2) */
		adjmulist[i].firstedge=p->jlink;
	else /* ��1���߲��Ǵ�ɾ���� */
	{
		while(p) /* �����һ�<v,w> */
		{
			if(p->ivex==i&&p->jvex!=j) /* ���Ǵ�ɾ���� */
			{
				q=p;
				p=p->ilink; /* ����һ���ڽӶ��� */
			}
			else if(p->jvex==i&&p->ivex!=j) /* ���Ǵ�ɾ���� */
			{
				q=p;
				p=p->jlink; /* ����һ���ڽӶ��� */
			}
			else /* ���ڽӶ���w */
				break;
		}
		if(!p) /* û�ҵ��ñ� */
			return;
		if(p->ivex==i&&p->jvex==j) /* �ҵ���<v,w>(���1) */
			if(q->ivex==i)
				q->ilink=p->ilink;
			else
				q->jlink=p->ilink;
		else if(p->ivex==j&&p->jvex==i) /* �ҵ���<v,w>(���2) */
			if(q->ivex==i)
				q->ilink=p->jlink;
			else
				q->jlink=p->jlink;
	}
	/* ��������һ�������Ҵ�ɾ������ɾ��֮ */
	p=adjmulist[j].firstedge; /* pָ�򶥵�w�ĵ�1���� */
	if(p->jvex==i) /* ��1���߼�Ϊ��ɾ����(���1) */
	{
		adjmulist[j].firstedge=p->ilink;
		free(p);
	}
	else if(p->ivex==i) /* ��1���߼�Ϊ��ɾ����(���2) */
	{
		adjmulist[j].firstedge=p->jlink;
		free(p);
	}
	else /* ��1���߲��Ǵ�ɾ���� */
	{
		while(p) /* �����һ�<v,w> */
			if(p->ivex==j&&p->jvex!=i) /* ���Ǵ�ɾ���� */
			{
				q=p;
				p=p->ilink; /* ����һ���ڽӶ��� */
			}
			else if(p->jvex==j&&p->ivex!=i) /* ���Ǵ�ɾ���� */
			{
				q=p;
				p=p->jlink; /* ����һ���ڽӶ��� */
			}
			else /* ���ڽӶ���v */
				break;
			if(p->ivex==i&&p->jvex==j) /* �ҵ���<v,w>(���1) */
			{
				if(q->ivex==j)
					q->ilink=p->jlink;
				else
					q->jlink=p->jlink;
				free(p);
			}
			else if(p->ivex==j&&p->jvex==i) /* �ҵ���<v,w>(���2) */
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
{ /* ��ʼ����: ����ͼG����,v��W��G���������� */
	/* �������: ��G������<v,w> */
	int i,j;
	EBox *p;
	i=LocateVex(v); /* һ�� */
	j=LocateVex(w); /* ��һ�� */
	if(i<0||j<0)
		return;
	p=new EBox;
	p->mark=0;
	p->ivex=i;
	p->jvex=j;
	p->ilink=adjmulist[i].firstedge; /* ���ڱ�ͷ */
	adjmulist[i].firstedge=p;
	p->jlink=adjmulist[j].firstedge; /* ���ڱ�ͷ */
	adjmulist[j].firstedge=p;
	edgenum++;
	return;
}

void UDGraph::Display()
{ /* �������ͼ���ڽӶ��ر�G */
	int i;
	EBox *p;
	for(i=0;i<vexnum;i++)
	{
		p=adjmulist[i].firstedge;
		while(p)
			if(p->ivex==i) /* �ߵ�i����ö����й� */
			{
				if(!p->mark) /* ֻ���һ�� */
				{
					cout<<'<'<<adjmulist[i].data<<','<<adjmulist[p->jvex].data<<'>'<<endl;
					p->mark=1;
				}
				p=p->ilink;
			}
			else /* �ߵ�j����ö����й� */
			{
				if(!p->mark) /* ֻ���һ�� */
				{
					cout<<'<'<<adjmulist[p->ivex].data<<','<<adjmulist[i].data<<'>'<<endl;
					p->mark=1;
				}
				p=p->jlink;
			}
			cout<<endl;
	}
}