// 7-14.cpp : �������̨Ӧ�ó������ڵ㡣
//
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
#include "stdafx.h"
#include "DGraph.h"
#include "iostream"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	DGraph G;
	G.Build_AdjList();
	cout<<"���ͼ�еıߣ�"<<endl;
	G.OutPutArc();
	cout<<endl;
	system("pause");
}

