// 7-24.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "DGraph.h"
#include "CSqStack.h"
#include "iostream"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	DGraph G;
	G.Build_AdjList();
	cout<<"按深度优先搜索遍历图的序列为："<<endl;
	G.DFSTraverse();
	cout<<endl;
	system("pause");
}

