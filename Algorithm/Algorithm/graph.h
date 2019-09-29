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
#define  MAXN 107        //����������ɵĵ�ĸ���
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