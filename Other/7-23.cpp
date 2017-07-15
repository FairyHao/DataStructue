// 7-23.cpp : 定义控制台应用程序的入口点。
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
	cout<<"判断从顶点v1到顶点v2之间是否有路径:"<<endl;
	cout<<" v1=";
	cin>>v1;
	cout<<" v2=";
	cin>>v2;
	i=G.LocateVex(v1);
	j=G.LocateVex(v2);
	k=G.Judge_Pass_BFS(i,j);
	if(k==1)
		cout<<"v1到v2之间有路径！"<<endl;
	else 
		cout<<"v1到v2之间没有路径！"<<endl;
}

