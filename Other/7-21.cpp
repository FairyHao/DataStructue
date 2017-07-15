// 7-21.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Graph.h"
#include "iostream"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	Graph G;
	int n;
	G.Build_AdjList();
	cout<<"判断无向图是否可传递：";
	n=G.Judge_Pass_MGraph();
	if(n)
		cout<<"该图可传递。";
	else
		cout<<"该图不可传递。";
}

