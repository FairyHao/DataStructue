// 7-36.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "DGraph.h"
#include "iostream"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	DGraph G;
	G.CreateGraph();
	G.Fill_MPL();
	G.OutPutPath_Length();
	system("pause");
}

                                       