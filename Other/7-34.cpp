// 7-34.cpp : �������̨Ӧ�ó������ڵ㡣
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
	cout<<"���ͼ�еıߣ�"<<endl;
	G.OutPutArc();
	cout<<"��ÿ�����㸳��һ���������,�������"<<endl;
	G.TopoSeq();
	system("pause");
}

