// 7-32.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "UDGraph.h"
#include "iostream"
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	UDGraph G;
	CSNode *T=NULL;
	T=new CSNode;
	T->data=NULL;
	T->firstchild=NULL;
	T->nextsibing=NULL;
	G.CreateGraph();
	cout<<"���ͼ�еıߣ�"<<endl;
	G.OutPutArc();

	cout<<"���뿪ʼ�Ķ��㣺";
	cin>>T->data;
	G.Forest_Prim(T->data,T);

	cout<<"�����������������ֵ�����"<<endl;
	G.PreOrderTraverse(T);
	cout<<endl;

	cout<<"�����������������ֵ�����"<<endl;
	G.InOrderTraverse(T);
	cout<<endl;
	system("pause");
}

