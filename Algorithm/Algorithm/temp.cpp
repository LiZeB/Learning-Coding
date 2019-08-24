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
#define MAXN 107        //做多可以容纳的点的个数
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

void Dijkstra::AddEdge(int from, int to, int dist){
	/**************************************************
	这个函数完成用邻接表来表示一张图的功能
	表达无向图时需要把这6行全加上；有向图只需要加前三行
	****************************************************/
	edges.push_back(Edge(from, to, dist));
	m = edges.size();
	G[from].push_back(m - 1); 
	edges.push_back(Edge(to, from, dist));
	m = edges.size();
	G[to].push_back(m - 1);
}

void Dijkstra::dijkstra(int s){
	/**************************************************************
	这个Dijkstra算法的实现稍微有点难以理解。原因是它用到了优先队列；
	而且还重载了默认的比较运算符，导致从当前节点到它的子节点中取最近
	这一步被省略掉了，仅仅只有如优先队列的操作。
	在这里将Dijkstra的操作归纳一下：
	1)	取当前节点，依次遍历当前节点的子节点，视情况决定是否修改源节点到该子节点路径和距离；
	2)	从当前子节点中取一个源节点到子节点路径距离最短的子节点作为下一个当前节点，到1中循环，
	继续修改源节点到各子节点的路径距离。
	当前节点初始化时是源节点；
	****************************************************************/
	priority_queue<HeapNode> Q;   //优先队列
	for (int i = 0; i<n; i++)
		d[i] = INF;
	d[s] = 0;
	memset(done, 0, sizeof(done));   //从done开始sizeof(done)个字节都初始化为0
	HeapNode temp;
	temp.d = 0; temp.u = s;
	Q.push(temp);
	while (!Q.empty())
	{
		HeapNode x = Q.top();
		Q.pop();
		int u = x.u;
		if (done[u])
			continue;
		done[u] = true;
		for (int i = 0; i<G[u].size(); i++)
		{
			Edge& e = edges[G[u][i]];
			//修改当前节点的子节点的路径和路径距离
			if (d[e.to]>d[u] + e.dist)
			{
				d[e.to] = d[u] + e.dist;
				pp[e.to].clear();
				for (int j = 0;j < pp[u].size();j++)   //将之前的到u这个节点的最短路径添加进去
				{
					pp[e.to].push_back(pp[u][j]);
				}
				pp[e.to].push_back(u);   //将u这个当前节点添加到路径里去

				//将最前子节点添加到最优队列中，因为时最优队列，下一次pop时会自动把最短路径距离的子节点pop出来
				HeapNode temp;
				temp.d = d[e.to]; temp.u = e.to;    //注意这个入队操作，相当于把u的邻接节点添加到队列中去
				Q.push(temp);
			}
		}
	}

	//加上各条最短路径的最后一个点
	for (int i = 0;i < MAXN;i++)
	{
		pp[i].push_back(i);
	}
}

int main() {
	ifstream input("out.txt", ifstream::in);
	int nodenum, edgenum, source;         //节点数目、边的数目、源点
	int from, to, weight;                 //一条边的起点、终点和权值
	string line;

	if (getline(input, line)) {
		istringstream s1(line);
		s1 >> nodenum >> edgenum >> source;
	}

	Dijkstra dij(nodenum);

	for (int i = 1; i <= edgenum; i++)
	{
		getline(input, line);
		istringstream s1(line);
		s1 >> from >> to >> weight;
		dij.AddEdge(from, to, weight);
	}

	dij.dijkstra(source);

	ofstream output("result.txt", ofstream::out);
	for (int i = 0; i<nodenum; i++)
	{
		if(dij.d[i] == INF)
			output << "源点"<< (char)(source+65) <<"到点" << (char)(i + 65) << "的最短路径长度是：inf"<< endl;
		else
			output << "源点" << (char)(source + 65) << "到点" << (char)(i + 65) << "的最短路径长度是：" 
			<< dij.d[i]<< endl;
		for (int j = 0;j < dij.pp[i].size();j++)
		{
			output << (char)(dij.pp[i][j] + 65) << " ";
		}
		output << endl;
	}
}