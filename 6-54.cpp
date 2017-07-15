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
}BiTnode, *BiTree;

typedef struct sqList
{
	char *elem;
	int last;	int length;
}sqList;

sqList* createList()
{
	sqList *sa = (sqList*)malloc(sizeof(sqList));
	sa->elem = (char*)malloc(sizeof(char)*1000);
	sa->length = 0;
	for (int i = 0; i < 10;i++)
	{
		sa->last = i;
		sa->elem[i] = i + 'a';
		sa->length++;
	}
	return sa;
}
BiTree createTree(sqList *sa,int i)
{
	if (i>=sa->length)
	{
		return NULL;
	}
	BiTree t = (BiTree)malloc(sizeof(BiTnode));
	t->data = sa->elem[i];
	t->lchild = createTree(sa, 2 * i+1);
	t->rchild = createTree(sa, 2 * i+2);
	return t;
}

int main()
{
	char tree[] = "a  ";// abd g  e  c f    ab  c  
	sqList *sa = createList();
	BiTree t = createTree(sa, 0);
	while (1)
	{
	}
}