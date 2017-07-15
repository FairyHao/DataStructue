#include <iostream>
using namespace std;
#define STACK_INIT_SIZE 10
typedef int Status;

#define ERROR 0
#define OK 1
#define INFEASIBLE 2

#define Max_Tree_SIZE 5

typedef struct
{
	char data;
	int parent;
}PTNode;
typedef struct
{
	PTNode nodes[Max_Tree_SIZE];
	int r; int n;
}PTree;

PTree* createPtree()
{
	PTree *pt = (PTree*)malloc(sizeof(PTree));
	for (int i = 0; i < Max_Tree_SIZE; i++)
	{
		PTNode *pn = (PTNode*)malloc(sizeof(PTNode));
		pn->data = 'A' + i;
		int parent;
		cin >> parent;	
		pn->parent = parent;
		pt->nodes[i] = *pn;
	}
	pt->n = Max_Tree_SIZE;
	pt->r = 0;
	return pt;
}

int depth(PTree *pt, int x)
{
	if (x>pt->n)
	{
		return 0;
	}
	int max = 0;
	for (int i = 0; i < pt->n;i++)
	{
		if (pt->nodes[i].parent==x)
		{
			int xx = depth(pt, i);
			if (max < xx)
			{
				max = xx;
			}
		}
	}
	return max+1;
}

int main()
{
	PTree *pt = createPtree();
	cout<<"Éî¶ÈÎª"<<depth(pt,pt->r);
	while (1)
	{
	}
	return 0;
}