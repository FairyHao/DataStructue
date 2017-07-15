#include <iostream>
using namespace std;
#define MAX_VERTEX_NUM 3
class ArcInfoType
{
public:
	int weight;
};
class ArcCell
{
public:
	int weight;
	ArcInfoType *it;
	ArcCell()
	{
		this->weight = 0;
		this->it = NULL;
	}
	ArcCell(int weight, ArcInfoType* it)
	{
		this->weight = weight;
		this->it = it;
	}
};
class MGraph
{
public:
	char vexs[MAX_VERTEX_NUM];
	ArcCell arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
	MGraph()
	{
		createMGraph();
	}	
	void createMGraph()
	{
		for (int i = 0; i < MAX_VERTEX_NUM;i++)
		{
			this->vexs[i] = i + '0';
		}
		//this->vexs[MAX_VERTEX_NUM] = { '1', '2', '3', '4', '5', '6' };给一个数组赋值
		char v1, v2;
		for (int i = 0; i < MAX_VERTEX_NUM; i++)
		{
			cin >> v1;
			cin >> v2; 
			int x = 0;
			int y = 0; 
			ArcCell arc;
			for (int j = 0; j <MAX_VERTEX_NUM; j++)
			{
				if (v1 == vexs[j])
				{
					x = j;
				}
				if (v2 == this->vexs[j])
				{
					y = j;
				}
			}
			arc.weight = 1;
			arcs[x][y] = arc;
		}
}
};
int main()
{
	MGraph mg;
	while (1)
	{
	}
}