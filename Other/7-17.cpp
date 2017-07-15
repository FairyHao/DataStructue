// 7-17.cpp : 定义控制台应用程序的入口点。
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
	cout<<"输出图中的边："<<endl;
	G.OutPutArc();
	cout<<endl;

	G.InsertVex();
	G.OutPutArc();
	cout<<endl;

	cout<<"输入要删除的顶点：";
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

