// 7-41.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "DGraph.h"
#include "iostream"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	DGraph G;
	G.CreateGraph();
	cout<<"����ؼ�·����"<<endl;
	G.Critical_Path();
	cout<<endl;
	system("pause");
}

