#include <iostream>
using namespace std;
typedef int Status;

#define ERROR 0
#define OK 1
#define INFEASIBLE 2

#define MAX_Tree_SIZE 10

typedef struct CTNode
{
	int child;
	struct CTNode *next;
}*childPtr;
typedef struct
{
	char data;
	childPtr firstchild;
}CTBox;
typedef struct
{
	CTBox nodes[MAX_Tree_SIZE];
	int n, r;
}CTree;

CTree* CreateCTree()
{
	CTree *ct = (CTree*)malloc(sizeof(CTree));
	//定义了一个nodes[10]，CTBox nodes[10];然后赋值：ct->nodes = nodes,编译就会报错,左边是不可编译的？？？？不知道为什么
	for(int i = 0;i<10;i++)
	{
		CTBox *cb = (CTBox*)malloc(sizeof(CTBox));
		cb->data = i+ 'A';
		cb->firstchild = NULL;
		ct->nodes[i] = *cb;
	}
	/*
	childPtr cp1 = (childPtr)malloc(sizeof(CTNode));
	cp1->child = 5;
	cp1->next = NULL;
	childPtr cp2 = (childPtr)malloc(sizeof(CTNode));
	cp2->child = 3;
	cp2->next = cp1;
	ct->nodes[0].firstchild = cp2;*/
	/*
	childPtr cp3 = (childPtr)malloc(sizeof(CTNode));
	cp3->child = 6;
	cp3->next = NULL;
	ct->nodes[2].firstchild = cp3;*/

	childPtr cp4 = (childPtr)malloc(sizeof(CTNode));
	cp4->child = 2;
	cp4->next = NULL;
	childPtr cp5 = (childPtr)malloc(sizeof(CTNode));
	cp5->child = 1;
	cp5->next = cp4;
	childPtr cp6 = (childPtr)malloc(sizeof(CTNode));
	cp6->child = 0;
	cp6->next = cp5;
	ct->nodes[4].firstchild = cp6;
	ct->n = 10;
	ct->r = 4;
	return ct;
}
//对孩子链表表示的树计算树的深度
//算法思想：求每个结点的所有孩子的深度加1，并求出最大值，即为此数的深度
int depth(CTree *ct,int i)
{
	if(!ct||i>ct->n)
	{
		return 0;
	}
	if(!(ct->nodes[i].firstchild))
	{
		return 1;
	}
	int max = 0;
	childPtr p = ct->nodes[i].firstchild;
	while(p)
	{
		int x = depth(ct,p->child);
		if(x > max)
		{
			max = x;
		}
		p = p->next;
	}
	return max+1;
}
int main()
{
	CTree *t = CreateCTree();
	cout<<depth(t,t->r);
	while (1)
	{
	}
	return 0;
}
