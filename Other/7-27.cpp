// 7-27.cpp : �������̨Ӧ�ó������ڵ㡣
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
	cout<<"�ж�����������֮���Ƿ����һ������Ϊ k �ļ�·����"<<endl;
	cout<<"�����������㣺";
	cin>>v1>>v2;
	cout<<"���� k ��ֵ��k = ";
	cin>>k;
	i=G.LocateVex(v1);
	j=G.LocateVex(v2);
	l=G.Exist_path_len(i,j,k,-1);
	if(l==1)
	{
		cout<<"����һ������Ϊ "<<k<<" �ļ�·��!"<<endl;
		for(int i=0;i<k;i++)
		{
			cout<<G.vertices[path[i]].data<<" -> ";
		}
		cout<<G.vertices[path[k]].data<<endl;
	}
	else 
		cout<<"������һ������Ϊ "<<k<<" �ļ�·��!"<<endl;
	system("pause");
}

