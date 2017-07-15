// 7-14Cplusplus.cpp : 定义控制台应用程序的入口点。
//
#include "iostream"
using namespace std;
#define MAX_VERTEX_NUM 6
class ArcNode//Arc:弧
{
public:
	int adjvex;//adj:adjacency:邻接；ver:vertex:顶点。
	ArcNode *nextarc;//下一条弧
};
class Vnode
{
public:
	char data;
	ArcNode *firstArc;
	Vnode()
	{}
	Vnode(char data, ArcNode *firstArc)
	{
		this->data = data;
		this->firstArc = firstArc;
	}
};
class ALGraph//有向图类
{
private:
public:
	Vnode vertices[MAX_VERTEX_NUM];//存储顶点结点的数组
	int vernum, arcnum; //图的当前顶点数和弧数
	ALGraph(void)
	{
		createALGraph();
		cout << "执行完毕";
	}
	~ALGraph(void)
	{
	}
	void createALGraph()
	{
		char VNodeArray[] = { '1', '2', '3', '4', '5', '6' };
		this->vernum = 6;
		this->arcnum = 3;
		for (int i = 0; i < this->vernum; i++)
		{
			Vnode *vn = new Vnode(VNodeArray[i], NULL);
			this->vertices[i] = *vn;
		}
		char v1, v2;
		for (int i = 0; i < this->arcnum; i++)
		{
			ArcNode *arc = new ArcNode();
			cin >> v1;
			cin >> v2;
			int x;
			int y;
			for (int j = 0; j < this->vernum; j++)
			{
				if (v1 == this->vertices[j].data)
				{
					x = j;
				}
				if (v2 == this->vertices[j].data)
				{
					y = j;
				}
			}
			arc->adjvex = y;
			arc->nextarc = NULL;
			ArcNode *p = this->vertices[x].firstArc;
			if (!p)
			{
				this->vertices[x].firstArc = arc;
			}
			else
			{
				while (p->nextarc)
				{
					p = p->nextarc;
				}
				p->nextarc = arc;
			}
		}
	}
};
int main()
{
	ALGraph *ag = new ALGraph();
	while (1)
	{
	}
	return 0;
}

