// 7-21.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Graph.h"
#include "iostream"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	Graph G;
	int n;
	G.Build_AdjList();
	cout<<"�ж�����ͼ�Ƿ�ɴ��ݣ�";
	n=G.Judge_Pass_MGraph();
	if(n)
		cout<<"��ͼ�ɴ��ݡ�";
	else
		cout<<"��ͼ���ɴ��ݡ�";
}

