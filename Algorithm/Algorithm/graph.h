#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
#include<cstdlib>
#include<map>
#include<set>
#include<sstream>
#include<fstream>
#include<queue>
#include<list>
#include<vector>
#include<stack>
#include<deque>
#include<string>
#define  MAXN 107        //做多可以容纳的点的个数
#define INF 0xfffffff    //不可达的距离

using namespace std;

class Edge
{
public:
	Edge(int u, int v, int d) :from(u), to(v), dist(d) {}

	int from;
	int to;
	int dist;
};


class Dijkstra
{
public:
	Dijkstra(int n)          //初始化，将邻接表和边的vector清空
	{
		this->n = n;
		for (int i = 0; i<n; i++)
			G[i].clear();
		edges.clear();
	}
	void AddEdge(int, int, int);
	void dijkstra(int);

public:
	int n, m;
	vector<Edge> edges;     //存边
	vector<int> G[MAXN];    //存邻接表
	bool done[MAXN];        //是否已经永久标号
	int d[MAXN];            //s到各个点的距离
	vector<int> pp[MAXN];   //存最短路径

	/*优先队列默认最大堆，即从大到小排列，
	而迪杰斯特拉算法是寻找的最小路径，
	所以要选择重载的<运算符,实现最小堆*/
	struct HeapNode
	{
		int d, u;
		bool operator < (const HeapNode& rhs) const
		{
			return d>rhs.d;
		}
	};
};

void test_dijkstra();