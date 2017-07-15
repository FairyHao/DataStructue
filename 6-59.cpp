#include <iostream>
using namespace std;
#define STACK_INIT_SIZE 10
typedef int Status;

#define ERROR 0
#define OK 1
#define INFEASIBLE 2

typedef struct CSNode
{
	char data;
	struct CSNode *firstchild, *nextsibling;
}CSNode, *CSTree;
int i = 0;
CSTree createCStree(char s[])
{
	char ch = s[i++];
	if (ch == ' ')
	{
		return NULL;
	}
	CSTree ct;
	if (!(ct = (CSTree)malloc(sizeof(CSNode))))
	{
		return ERROR;
	}
	ct->data = ch;
	ct->firstchild = createCStree(s);
	ct->nextsibling = createCStree(s);
	return ct;
}
//6-59
Status printEdge(CSTree ct,CSTree parent)
{
	if (ct&&parent)
	{
		cout << '(' << ct->data << ',' << parent->data<<')'<<endl;
	}
	if (ct&&ct->firstchild)
	{
		printEdge(ct->firstchild, ct);
	}
	if (ct&&ct->nextsibling)
	{
		printEdge(ct->nextsibling,parent);
	}
	return OK;
}
//6-60
int computeNodeNum(CSTree ct)
{
	if (!ct)
	{
		return 0;
	}
	if (!ct->firstchild)
	{
		return 1 + computeNodeNum(ct->nextsibling);
	}
	return computeNodeNum(ct->firstchild) + computeNodeNum(ct->nextsibling);
} 
int Max(int a, int b, int c)
{
	int x = a > b ? a : b;
	return x > c ? x : c;
}
//6-61树的度为树的每结点的度的最大值
//int max;
int degree(CSTree ct)
{
	if (!ct)
	{
		return 0;
	}
	if (!ct->firstchild)
	{
		return 0;
	}
	CSTree p = ct->firstchild;
	int i = 0;
	while (p)
	{
		i++;
		p = p->nextsibling;
	}
	return Max(degree(ct->firstchild), degree(ct->nextsibling), i);
}

//6-62
 int depth(CSTree t)
{
	if (t)
	{
		int x2;
		CSTree p = t->firstchild; 
		int depthmax = 0;
		while (p)
		{
			x2 = depth(p);
			p = p->nextsibling;
			if (x2 > depthmax)
			{
				depthmax = x2;
			}
		}
		depthmax = depthmax + 1; 
		return depthmax;
	}
	else
	{
		return 0;
	}
}
// 树的深度
int Depth(CSTree& T)
{
	 int d1, d2;
	 if (T){
		d1 = 1 + Depth(T->firstchild);
		d2 = Depth(T->nextsibling);
		return d1 > d2 ? d1 : d2;
	}
		else return 0;
	 }
int main() 
{
	char s[] = "RAD  B CFG H K   D   ";//RAD  B CFG H K   D   2222222222   
	CSTree ct = createCStree(s);
	//printEdge(ct, NULL);
	//cout<<computeNodeNum(ct);
	//degree(ct);
	//cout << max << endl;
	cout << degree(ct) << endl;
	//cout << depth(ct);
	while (1)
	{
	}
}
