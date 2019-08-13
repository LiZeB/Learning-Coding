#include<iostream>
#include<sstream>

using namespace std;

template<class T>
class edge {
public:
	virtual int vertex1() const = 0;
	virtual int vertex2() const = 0;
	virtual T weight() const = 0;
};

template <class T>
class weightedEdge : public edge<T>
{
public:
	weightedEdge() {};
	weightedEdge(int theV1, int theV2, T theW)
	{
		v1 = theV1; v2 = theV2; w = theW;
	}
	~weightedEdge() {};
	int vertex1() const { return v1; }
	int vertex2() const { return v2; }
	T weight() const { return w; }
	operator T() const { return w; }
	void output(ostream& out) const
	{
		out << "(" << v1 << ", " << v2 << ", " << w << ")";
	}
private:
	int v1, v2;
	T w;
};

template <class T>
ostream& operator<<(ostream& out, const weightedEdge<T>& x)
{
	x.output(out); return out;
}

template<class T>
class vertexIterator {
public:
	virtual ~vertexIterator() {}
	virtual int next() = 0;
	virtual int next(T&) = 0;
};

template<class T>
class graph {
public:
	virtual ~graph() {}
	virtual int numberOfVertices() const = 0;   //返回图的顶点数
	virtual int numberOfEdges() const = 0;      //返回图的边数
	virtual bool existsEdge(int, int) const = 0;      //检查某条边是否存在
	virtual void insertEdge(edge<T>*) = 0;     //添加一条边
	virtual void eraseEdge(int, int) = 0;      //删除一条边
	virtual int degree(int) const = 0;        //返回某一个顶点的度
	virtual int inDegree(int) const = 0;      //返回某一个顶点的入度
	virtual int outDegree(int) const = 0;     //返回某一个顶点的出度

	virtual bool directed() const = 0;        //检查是否为有向图
	virtual bool weighted() const = 0;        //检查是否为加权图
	virtual vertexIterator<T>* iterator(int) = 0;    //访问指定顶点的相邻顶点
};

/**************************************************
 用邻接矩阵的表示方式实现了一个有向图
***************************************************/
template<class T>
class adjacencyWDigraph : public graph<T>
{
protected:
	int n;           //顶点个数
	int e;           //边的个数
	T **a;           // 邻接数组
	T noEdge;        // 表示不存在的边

public:
	adjacencyWDigraph(int numberOfVertices = 0, T theNoEdge = 0){
		if (numberOfVertices < 0) {
			cout << "图个顶点的个数必须大于0！" << endl;
			getchar();
		}	
		n = numberOfVertices;
		e = 0;
		noEdge = theNoEdge;
		a = new T*[n+1];
		for (int i = 1; i <= n; i++) {
			a[i] = new T[n + 1];
			for (int j = 1;j <= n;j++) {
				a[i][j] = noEdge;
			}
		}
	}

	~adjacencyWDigraph() {
		for (int i = 1; i <= n;i++) {      //一开始这个地方写成i=0,报delete一个不是new出来的内存的错误
			delete a[i];
		}
		delete a;
	}

	int numberOfVertices() const { return n; }

	int numberOfEdges() const { return e; }

	bool directed() const { return true; }

	bool weighted() const { return true; }

	bool existsEdge(int i, int j) const{ 
		if (i < 1 || j < 1 || i > n || j > n || a[i][j] == noEdge)
			return false;
		else
			return true;
	}

	void insertEdge(edge<T> *theEdge){
		int v1 = theEdge->vertex1();
		int v2 = theEdge->vertex2();
		if (v1 < 1 || v2 < 1 || v1 > n || v2 > n || v1 == v2)
		{
			ostringstream s;
			s << "(" << v1 << "," << v2
				<< ") is not a permissible edge";
			cout <<"插入的边不正确！" << s.str();
		}

		if (a[v1][v2] == noEdge)  
			e++;
		a[v1][v2] = theEdge->weight();
	}

	void eraseEdge(int i, int j){
		if (i >= 1 && j >= 1 && i <= n && j <= n && a[i][j] != noEdge)
		{
			a[i][j] = noEdge;
			e--;
		}
	}

	void checkVertex(int theVertex) const{
		if (theVertex < 1 || theVertex > n)
		{
			ostringstream s;
			s << "no vertex " << theVertex;
			cout<<"输入的顶点不合法！"<<s.str();
		}
	}

	int outDegree(int theVertex) const{
		checkVertex(theVertex);

		int sum = 0;
		for (int j = 1; j <= n; j++)
			if (a[theVertex][j] != noEdge)
				sum++;

		return sum;
	}

	int inDegree(int theVertex) const{
		checkVertex(theVertex);

		int sum = 0;
		for (int j = 1; j <= n; j++)
			if (a[j][theVertex] != noEdge)
				sum++;

		return sum;
	}

	int degree(int theVertex) const {
		return this->inDegree(theVertex) + this->outDegree(theVertex);
	}

	class myIterator : public vertexIterator<T>{
	public:
		myIterator(T* theRow, T theNoEdge, int numberOfVertices)
		{
			row = theRow;
			noEdge = theNoEdge;
			n = numberOfVertices;
			currentVertex = 1;
		}

		~myIterator() {}

		int next(){
			for (int j = currentVertex; j <= n; j++)
				if (row[j] != noEdge)
				{
					currentVertex = j + 1;
					return row[j];
				}
			currentVertex = n + 1;
			return 0;
		}

		int next(T& theWeight){
			for (int j = currentVertex; j <= n; j++)
				if (row[j] != noEdge)
				{
					currentVertex = j + 1;
					theWeight = row[j];
					return j;
				}
			currentVertex = n + 1;
			return 0;
		}

	protected:
		T* row;           // 邻接矩阵的一行
		T noEdge;         // 表示不存在的边
		int n;            // 顶点的个数
		int currentVertex;     //当前顶点
	};

	myIterator* iterator(int theVertex)   //对邻接矩阵的某一行生成迭代器
	{
		checkVertex(theVertex);
		return new myIterator(a[theVertex], noEdge, n);
	}

	void output(ostream& out) const{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n;j++) {
				cout << a[i][j] << " ";
			}
			out << endl;
		}
	}
};

template <class T>
ostream& operator<<(ostream& out, const adjacencyWDigraph<T>& x){
	x.output(out); return out;
}

void test_graph();