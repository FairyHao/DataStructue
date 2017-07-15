// 7-32.cpp : 定义控制台应用程序的入口点。
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
	cout<<"输出图中的边："<<endl;
	G.OutPutArc();

	cout<<"输入开始的顶点：";
	cin>>T->data;
	G.Forest_Prim(T->data,T);

	cout<<"按先序次序输出孩子兄弟链表："<<endl;
	G.PreOrderTraverse(T);
	cout<<endl;

	cout<<"按中序次序输出孩子兄弟链表："<<endl;
	G.InOrderTraverse(T);
	cout<<endl;
	system("pause");
}

