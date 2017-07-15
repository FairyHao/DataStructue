// 7-34.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "DGraph.h"
#include "Stack.h"
#include "iostream"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	DGraph G;
	G.CreateGraph();
	cout<<"输出图中的边："<<endl;
	G.OutPutArc();
	cout<<"将每个顶点赋以一个整数序号,并输出："<<endl;
	G.TopoSeq();
	system("pause");
}

