// 7-31.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "DGraph.h"
#include "iostream"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	DGraph G;
	G.Create_DGraph();
	cout<<"输出图中所有的边："<<endl;
	G.OutPutArc();
	cout<<"输出强连通分量："<<endl;
	G.Get_SGraph();
	cout<<endl;
	system("pause");
}

