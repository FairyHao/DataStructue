// 7-20.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Graph.h"
#include "iostream"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	Graph G;
	int m;
	G.CreateGraph();
	cout<<"�ж�����ͼ�Ƿ�Ϊ�ɴ��ݵ�:";
	m=G.Judge_Pass_MGraph();
	if (m)
		cout<<"��ͼ�ɴ��ݡ�";
	else
		cout<<"��ͼ���ɴ��ݡ�";

}

