// 7-35.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "DGraph.h"
#include "iostream"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	DGraph G;
	G.CreateGraph();
	cout<<"���ͼ�еıߣ�"<<endl;
	G.OutPutArc();
	G.Get_Root();
	system("pause");
}

