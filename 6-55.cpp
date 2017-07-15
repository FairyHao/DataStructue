#include <iostream>

using namespace std;
typedef int Status;

#define ERROR 0
#define OK 1
#define INFEASIBLE 2

typedef struct BiTnode
{
	char data;
	struct BiTnode *lchild, *rchild;
	int descNum;
}BiTnode, *BiTree;
//这个算法的时间复杂度为O(n)
int ComputeDescNum(BiTree t)
{
	if (!t)
	{
		return 0;
	}
	int x = 0;int y = 0;
	if (t->lchild)
	{
		x = ComputeDescNum(t->lchild) + 1;
	}
	if (t->rchild)
	{
		y = ComputeDescNum(t->rchild) + 1;
	}
	t->descNum = x + y;
	return x+y;
}
int i = 0;
BiTree Create(char s[])
{
	char ch;
	ch = s[i++];
	BiTree t;
	if (ch == ' ')
	{
		t = NULL;
	}
	else
	{
		if (!(t = (BiTree)malloc(sizeof(BiTnode))))
		{
			printf("fail to malloc!\n");
			exit(0);
		}
		else
		{
			t->data = ch;
			t->lchild = Create(s);
			t->rchild = Create(s);
		}
	}
	return t;
}
int main()
{
	char tree[] = "abd g  e  c f  ";// abd g  e  c f    ab  c  
	BiTree bt = Create(tree);
	cout << ComputeDescNum(bt) << endl;
	while (1)
	{
	}
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  