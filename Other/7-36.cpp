// 7-36.cpp : �������̨Ӧ�ó������ڵ㡣
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

                                       