// 7-24.cpp : �������̨Ӧ�ó������ڵ㡣
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
	cout<<"�����������������ͼ������Ϊ��"<<endl;
	G.DFSTraverse();
	cout<<endl;
	system("pause");
}

