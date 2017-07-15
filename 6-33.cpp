#include "stdafx.h"
#include <iostream>
using namespace std;
int n = 7;
int L[] = { 1, 2, 4, 5, 0, 0, 0,0 };
int R[] = { 0,3,0,6,7,0,0,0 };
bool visit(int u,int v);
int main()
{
	int u = 8;
	int v = 3;
	if (visit(u,v))
	{
		cout << u<<"yes" << endl;
	}
	else
	{
		cout << u << "no" << endl;
	}
	while (1)
	{
	}
	return 0;
}
//即节点V的孩子是U吗？如果是U，则返回true，
//如果不是U，则判断节点U是否是节点V的孩子的孩子,依次类推
bool visit(int u,int v)//节点U是否是节点V的子孙
{
	if (v==0)
	{
		return false;
	}
	if (L[v]==u||R[v]==u)
	{
		return true;
	}
	if (L[v]!=0)
	{
		if (visit(u, L[v]))
		{
			return true;
		}
	}
	if (R[v]!=0)
	{
		return visit(u, L[v]);
	}
	return false;
}