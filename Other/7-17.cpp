// 7-17.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "DGraph.h"
#include "iostream"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	DGraph G;
	char c;
	G.CreateDG();
	cout<<"���ͼ�еıߣ�"<<endl;
	G.OutPutArc();
	cout<<endl;

	G.InsertVex();
	G.OutPutArc();
	cout<<endl;

	cout<<"����Ҫɾ���Ķ��㣺";
	cin>>c;
	G.DeleteVex(c);
	G.OutPutArc();
	cout<<endl;

	G.InsertArc();
	G.OutPutArc();
	cout<<endl;

	G.DeleteArc();
	G.OutPutArc();
	cout<<endl;

	system("pause");
}

