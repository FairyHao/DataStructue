// 7-42.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "DGraph.h"
#include "iostream"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	DGraph G;
	char ch;
	int k;
	G.CreateGraph();
	cout<<"����Դ���㣺";
	cin>>ch;
	cout<<"��Ӷ��� "<<ch<<" �����ඥ������·����"<<endl;
	k=G.LocateVex(ch);
	G.ShortestPath_DIJ(k);
	G.OutPutPath(k);
	system("pause");
}

