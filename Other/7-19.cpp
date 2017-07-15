// 7-19.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "UDGraph.h"
#include "iostream"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	UDGraph G;

	G.CreateUDG();
	cout<<"输出图中的边："<<endl;
	G.Display();
	cout<<endl;
}

