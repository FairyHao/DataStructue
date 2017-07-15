// 7-27.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "UDGraph.h"
#include "iostream"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int k,l=0;
	int i,j;
	char v1,v2;
	UDGraph G;
	G.CreateUDGraph();
	G.OutPutArc();
	cout<<endl;
	cout<<"判断在两个顶点之间是否存在一条长度为 k 的简单路径："<<endl;
	cout<<"输入两个顶点：";
	cin>>v1>>v2;
	cout<<"输入 k 的值：k = ";
	cin>>k;
	i=G.LocateVex(v1);
	j=G.LocateVex(v2);
	l=G.Exist_path_len(i,j,k,-1);
	if(l==1)
	{
		cout<<"存在一条长度为 "<<k<<" 的简单路径!"<<endl;
		for(int i=0;i<k;i++)
		{
			cout<<G.vertices[path[i]].data<<" -> ";
		}
		cout<<G.vertices[path[k]].data<<endl;
	}
	else 
		cout<<"不存在一条长度为 "<<k<<" 的简单路径!"<<endl;
	system("pause");
}

