// 7-14.cpp : 定义控制台应用程序的入口点。
//
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
#include "stdafx.h"
#include "DGraph.h"
#include "iostream"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	DGraph G;
	G.Build_AdjList();
	cout<<"输出图中的边："<<endl;
	G.OutPutArc();
	cout<<endl;
	system("pause");
}

