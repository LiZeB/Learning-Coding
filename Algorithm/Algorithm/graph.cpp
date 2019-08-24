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
#define MAXN 107        //����������ɵĵ�ĸ���
#define INF 0xfffffff    //���ɴ�ľ���

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
	Dijkstra(int n)          //��ʼ�������ڽӱ�ͱߵ�vector���
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
	vector<Edge> edges;     //���
	vector<int> G[MAXN];    //���ڽӱ�
	bool done[MAXN];        //�Ƿ��Ѿ����ñ��
	int d[MAXN];            //s��������ľ���
	vector<int> pp[MAXN];   //�����·��

							/*���ȶ���Ĭ�����ѣ����Ӵ�С���У�
							���Ͻ�˹�����㷨��Ѱ�ҵ���С·����
							����Ҫѡ�����ص�<�����,ʵ����С��*/
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
	�������������ڽӱ�����ʾһ��ͼ�Ĺ���
	�������ͼʱ��Ҫ����6��ȫ���ϣ�����ͼֻ��Ҫ��ǰ����
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
	���Dijkstra�㷨��ʵ����΢�е�������⡣ԭ�������õ������ȶ��У�
	���һ�������Ĭ�ϵıȽ�����������´ӵ�ǰ�ڵ㵽�����ӽڵ���ȡ���
	��һ����ʡ�Ե��ˣ�����ֻ�������ȶ��еĲ�����
	�����ｫDijkstra�Ĳ�������һ�£�
	1)	ȡ��ǰ�ڵ㣬���α�����ǰ�ڵ���ӽڵ㣬����������Ƿ��޸�Դ�ڵ㵽���ӽڵ�·���;��룻
	2)	�ӵ�ǰ�ӽڵ���ȡһ��Դ�ڵ㵽�ӽڵ�·��������̵��ӽڵ���Ϊ��һ����ǰ�ڵ㣬��1��ѭ����
	�����޸�Դ�ڵ㵽���ӽڵ��·�����롣
	��ǰ�ڵ��ʼ��ʱ��Դ�ڵ㣻
	****************************************************************/
	priority_queue<HeapNode> Q;   //���ȶ���
	for (int i = 0; i<n; i++)
		d[i] = INF;
	d[s] = 0;
	memset(done, 0, sizeof(done));   //��done��ʼsizeof(done)���ֽڶ���ʼ��Ϊ0
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
			//�޸ĵ�ǰ�ڵ���ӽڵ��·����·������
			if (d[e.to]>d[u] + e.dist)
			{
				d[e.to] = d[u] + e.dist;
				pp[e.to].clear();
				for (int j = 0;j < pp[u].size();j++)   //��֮ǰ�ĵ�u����ڵ�����·����ӽ�ȥ
				{
					pp[e.to].push_back(pp[u][j]);
				}
				pp[e.to].push_back(u);   //��u�����ǰ�ڵ���ӵ�·����ȥ

				//����ǰ�ӽڵ���ӵ����Ŷ����У���Ϊʱ���Ŷ��У���һ��popʱ���Զ������·��������ӽڵ�pop����
				HeapNode temp;
				temp.d = d[e.to]; temp.u = e.to;    //ע�������Ӳ������൱�ڰ�u���ڽӽڵ���ӵ�������ȥ
				Q.push(temp);
			}
		}
	}

	//���ϸ������·�������һ����
	for (int i = 0;i < MAXN;i++)
	{
		pp[i].push_back(i);
	}
}

void test_dijkstra() {
	/****************************************
	����dijkstra�㷨��ע������output.txt����
	��ǰͼ���ڽӱ���Ϣ���ļ��ĵ�һ����
	�ڵ���Ŀ �ߵ���Ŀ Դ��
	result.txt������Դ�ڵ㵽���ӽڵ��·���;��룻
	���ﵱ������ͼ������·��ʱҲ��0����ʾ
	*****************************************/
	ifstream input("out.txt", ifstream::in);
	int nodenum, edgenum, source;         //�ڵ���Ŀ���ߵ���Ŀ��Դ��
	int from, to, weight;                 //һ���ߵ���㡢�յ��Ȩֵ
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
			output << "Դ��"<< (char)(source+65) <<"����" << (char)(i + 65) << "�����·�������ǣ�inf"<< endl;
		else
			output << "Դ��" << (char)(source + 65) << "����" << (char)(i + 65) << "�����·�������ǣ�" 
			<< dij.d[i]<< endl;
		for (int j = 0;j < dij.pp[i].size();j++)
		{
			output << (char)(dij.pp[i][j] + 65) << " ";
		}
		output << endl;
	}
}