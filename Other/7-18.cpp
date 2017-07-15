// 7-18.cpp : 定义控制台应用程序的入口点。
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
	cout<<"输出图中的边："<<endl;
	G.Display();
	cout<<endl;

	G.InsertVex();
	G.Display();
	cout<<endl;

	cout<<"输入要删除的顶点：";
	cin>>c;
	G.DeleteVex(c);
	G.Display();
	cout<<endl;

	cout<<"输入要增加边的两个顶点：";
	cin>>v>>w;
	G.InsertArc(v,w);
	G.Display();
	cout<<endl;

	cout<<"输入要删除边的两个顶点：";
	cin>>v>>w;
	G.DeleteArc(v,w);
	G.Display();
	cout<<endl;

	system("pause");
}

