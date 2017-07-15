// 7-42.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "DGraph.h"
#include "iostream"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	DGraph G;
	char ch;
	int k;
	G.CreateGraph();
	cout<<"输入源顶点：";
	cin>>ch;
	cout<<"求从顶点 "<<ch<<" 到其余顶点的最短路径："<<endl;
	k=G.LocateVex(ch);
	G.ShortestPath_DIJ(k);
	G.OutPutPath(k);
	system("pause");
}

