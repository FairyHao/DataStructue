// 7-23.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "DGraph.h"
#include "Queue.h"
#include "iostream"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int i,j,k;
	char v1,v2;
	DGraph G;
	G.Build_AdjList();
	cout<<"�жϴӶ���v1������v2֮���Ƿ���·��:"<<endl;
	cout<<" v1=";
	cin>>v1;
	cout<<" v2=";
	cin>>v2;
	i=G.LocateVex(v1);
	j=G.LocateVex(v2);
	k=G.Judge_Pass_BFS(i,j);
	if(k==1)
		cout<<"v1��v2֮����·����"<<endl;
	else 
		cout<<"v1��v2֮��û��·����"<<endl;
}

