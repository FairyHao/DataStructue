// 6-65-1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

using namespace std;
#define STACK_INIT_SIZE 10
typedef int Status;

#define ERROR 0
#define OK 1
#define INFEASIBLE 2

typedef struct BiTnode
{
	char data;
	struct BiTnode *lchild, *rchild;
}BiTnode, *BiTree;

BiTree createTree(char *s1, char *s2)//s1代表前序遍历序列，s2代表中序遍历序列
{
	if (s1 == NULL || *s1 == ' ')
	{
		return NULL;
	}
	BiTree t = (BiTree)malloc(sizeof(BiTnode));
	t->data = *s1;
	char *news22 = strchr(s2, *s1);
	char *p = news22;
	p--;
	char *q = (char*)malloc(sizeof(char));
	while (p != s2)
	{
		*q = *p;
		q--;
		p--;
	}
	*--q = *s2;
	char *news21 = q;
	char *news11 = ++s1;
	char *news12 = news11;
	for (int i = 0; i < strlen(s2); i++)
	{
		news12++;
	}
	t->lchild = createTree(news11, news21);
	t->rchild = createTree(news12, news22);
	return t;
}
int main()
{
	char *str1 = "abdfce";
	char *str2 = "dfbaec";
	BiTree t = createTree(str1, str2);
	while (1)
	{
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

