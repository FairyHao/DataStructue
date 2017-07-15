#include <iostream>
using namespace std;
#define MAX_VERTEX_NUM 3

class ArcBox
{
public:
	int tailVex, headVex;
	ArcBox *hlink;
	ArcBox *tlink;
};
class  VexNode
{
public:
	char data;
	ArcBox *fisrtIn, *firstout;

protected:
private:
};
class OLGraph
{
public:
	VexNode xList[MAX_VERTEX_NUM];
	int vexNum, arcnum;
	OLGraph()
	{
		vexNum = 0;
		this->arcnum = 3;
		createOLGraph();
	}
	void createOLGraph()
	{
		for (int i = 0; i < MAX_VERTEX_NUM;i++)
		{
			VexNode node;
			node.data = '0' + i;
			node.firstout = NULL;
			node.fisrtIn = NULL;
			this->xList[i] = node;
		}
		char v1, v2;
		for (int i = 0; i < this->arcnum;i++)
		{
			cout << "请输入弧头结点";
			cin >> v1;
			cout << "请输入弧尾结点";
			cin >> v2;
			
			ArcBox arc;
			arc.headVex = v1;
			arc.tailVex = v2;
			arc.hlink = NULL;
			arc.tlink = NULL;

			int x = locate(v1);
			int y = locate(v2);

			ArcBox *p = this->xList[x].fisrtIn;
			if (p)
			{
				while (p->tlink)
				{
					p = p->tlink;
				}
				p->tlink = &arc;
			}
			else
			{
				this->xList[x].fisrtIn = &arc;
			}
		}

	}
	int locate(char v)
	{
		for (int i = 0; i < MAX_VERTEX_NUM; i++)
		{
			if (this->xList[i].data == v)
			{
				return i;
			}
		}
		return 0;
	}
};

int main()
{
	OLGraph og;
	while (1)
	{
	}
}
