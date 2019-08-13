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
	virtual int numberOfVertices() const = 0;   //����ͼ�Ķ�����
	virtual int numberOfEdges() const = 0;      //����ͼ�ı���
	virtual bool existsEdge(int, int) const = 0;      //���ĳ�����Ƿ����
	virtual void insertEdge(edge<T>*) = 0;     //���һ����
	virtual void eraseEdge(int, int) = 0;      //ɾ��һ����
	virtual int degree(int) const = 0;        //����ĳһ������Ķ�
	virtual int inDegree(int) const = 0;      //����ĳһ����������
	virtual int outDegree(int) const = 0;     //����ĳһ������ĳ���

	virtual bool directed() const = 0;        //����Ƿ�Ϊ����ͼ
	virtual bool weighted() const = 0;        //����Ƿ�Ϊ��Ȩͼ
	virtual vertexIterator<T>* iterator(int) = 0;    //����ָ����������ڶ���
};

/**************************************************
 ���ڽӾ���ı�ʾ��ʽʵ����һ������ͼ
***************************************************/
template<class T>
class adjacencyWDigraph : public graph<T>
{
protected:
	int n;           //�������
	int e;           //�ߵĸ���
	T **a;           // �ڽ�����
	T noEdge;        // ��ʾ�����ڵı�

public:
	adjacencyWDigraph(int numberOfVertices = 0, T theNoEdge = 0){
		if (numberOfVertices < 0) {
			cout << "ͼ������ĸ����������0��" << endl;
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
		for (int i = 1; i <= n;i++) {      //һ��ʼ����ط�д��i=0,��deleteһ������new�������ڴ�Ĵ���
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
			cout <<"����ı߲���ȷ��" << s.str();
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
			cout<<"����Ķ��㲻�Ϸ���"<<s.str();
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
		T* row;           // �ڽӾ����һ��
		T noEdge;         // ��ʾ�����ڵı�
		int n;            // ����ĸ���
		int currentVertex;     //��ǰ����
	};

	myIterator* iterator(int theVertex)   //���ڽӾ����ĳһ�����ɵ�����
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