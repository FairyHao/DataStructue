// 7-31.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "DGraph.h"
#include "iostream"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	DGraph G;
	G.Create_DGraph();
	cout<<"���ͼ�����еıߣ�"<<endl;
	G.OutPutArc();
	cout<<"���ǿ��ͨ������"<<endl;
	G.Get_SGraph();
	cout<<endl;
	system("pause");
}

