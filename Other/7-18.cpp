// 7-18.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "UDGraph.h"
#include "iostream"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	UDGraph G;
	char c,v,w;

	G.CreateUDG();
	cout<<"���ͼ�еıߣ�"<<endl;
	G.Display();
	cout<<endl;

	G.InsertVex();
	G.Display();
	cout<<endl;

	cout<<"����Ҫɾ���Ķ��㣺";
	cin>>c;
	G.DeleteVex(c);
	G.Display();
	cout<<endl;

	cout<<"����Ҫ���ӱߵ��������㣺";
	cin>>v>>w;
	G.InsertArc(v,w);
	G.Display();
	cout<<endl;

	cout<<"����Ҫɾ���ߵ��������㣺";
	cin>>v>>w;
	G.DeleteArc(v,w);
	G.Display();
	cout<<endl;

	system("pause");
}

