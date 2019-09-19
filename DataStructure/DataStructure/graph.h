#include<iostream>
#include<sstream>
#include<queue>
#include<vector>

using namespace std;

/**********************���ߺ���*******************/
template<class T>
void operator <<(ostream &out, vector<T> &v) {
	for (auto i : v) {
		cout << i << " ";
	}
	cout << endl;
}

//����weightedEdge��������Ȩ��
template <class T>
class weightedEdge{
public:
	weightedEdge() {};
	weightedEdge(int theV1, int theV2, T theW){
		v1 = theV1; v2 = theV2; w = theW;
	}
	~weightedEdge() {};
	int vertex1() const { return v1; }
	int vertex2() const { return v2; }
	T weight() const { return w; }
	operator T() const { return w; }
	void output(ostream& out) const{
		out << "(" << v1 << ", " << v2 << ", " << w << ")";
	}
public:
	weightedEdge<T> *next;
private:
	int v1, v2;
	T w;
};

template <class T>
ostream& operator<<(ostream& out, const weightedEdge<T>& x){
	x.output(out);
	return out;
}

template<class T>
class vertexIterator {
public:
	virtual ~vertexIterator() {}
	virtual int next() = 0;
	virtual int next(T&) = 0;
};

/**********����һ��ͼ�ĳ�����***********/
template<class T>
class graph {
public:
	virtual ~graph() {}
	virtual int numberOfVertices() const = 0;   //����ͼ�Ķ�����
	virtual int numberOfEdges() const = 0;      //����ͼ�ı���
	virtual bool existsEdge(int, int) const = 0;      //���ĳ�����Ƿ����
	virtual void insertEdge(weightedEdge<T>*) = 0;     //���һ����
	virtual void eraseEdge(int, int) = 0;      //ɾ��һ����
	virtual int degree(int) const { return 0; }        //����ĳһ������Ķ�
	virtual int inDegree(int) const { return 0; }      //����ĳһ����������
	virtual int outDegree(int) const { return 0; }    //����ĳһ������ĳ���

	virtual bool directed() const = 0;        //����Ƿ�Ϊ����ͼ
	virtual bool weighted() const = 0;        //����Ƿ�Ϊ��Ȩͼ
	virtual void output(ostream &) const = 0;           //���һ��ͼ

	virtual vector<int> bfs(int) const { return vector<int>(); }  //�����������
	virtual vector<int> dfs(int) const { return vector<int>(); }   //�����������
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
	T **a;           // �ڽӾ���
	T noEdge;        // ��ʾ�����ڵı�

public:
	adjacencyWDigraph(int numberOfVertices = 0, T theNoEdge = 0){
		if (numberOfVertices < 0) {
			cout << "ͼ�ж���ĸ����������0��" << endl;
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
		for (int i = 1; i <= n;i++) {      //һ��ʼ����ط�д��i=0,����deleteһ������new�������ڴ�Ĵ���
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

	void insertEdge(weightedEdge<T> *theEdge){
		int v1 = theEdge->vertex1();
		int v2 = theEdge->vertex2();
		if (v1 < 1 || v2 < 1 || v1 > n || v2 > n || v1 == v2)
		{
			ostringstream s;
			s << "(" << v1 << "," << v2
				<< ") is not a permissible edge";
			cout <<"����ı߲���ȷ��" << s.str();
		}

		if (a[v1][v2] == noEdge) {
			e++;
			a[v1][v2] = theEdge->weight();
		}
		else {
			a[v1][v2] = theEdge->weight();
		}
	}

	void eraseEdge(int i, int j){
		if (i >= 1 && j >= 1 && i <= n && j <= n && a[i][j] != noEdge)
		{
			a[i][j] = noEdge;
			e--;
		}
	}

	bool checkVertex(int theVertex) const{
		if (theVertex < 1 || theVertex > n)
		{
			ostringstream s;
			s << "no vertex " << theVertex;
			cout<<"����Ķ��㲻�Ϸ���"<<s.str();
			return false;
		}
		return true;
	}

	int outDegree(int theVertex) const{
		if(checkVertex(theVertex))
			return 0;

		int sum = 0;
		for (int j = 1; j <= n; j++)
			if (a[theVertex][j] != noEdge)
				sum++;

		return sum;
	}

	int inDegree(int theVertex) const{
		if (checkVertex(theVertex))
			return 0;

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
		myIterator(T* theRow, T theNoEdge, int numberOfVertices){
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
				if (row[j] != noEdge){
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

	//���ڽӾ����ĳһ�����ɵ�����
	myIterator* iterator(int theVertex)   
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

/**************************************************
���ڽӱ�ķ�ʽʵ��һ������ͼ
***************************************************/
template<class T>
class adjacencyWDigraph2 : public graph<T>
{
protected:
	int n;           //�������
	int e;           //�ߵĸ���
	weightedEdge<T> **a;           // �ڽӱ�

public:
	adjacencyWDigraph2(int numberOfVertices = 0) {
		if (numberOfVertices < 0) {
			cout << "ͼ������ĸ����������0��" << endl;
			getchar();
		}
		n = numberOfVertices;
		e = 0;
		a = new weightedEdge<T>* [n + 1];
		for (int i = 1; i <= n; i++) {
			a[i] = NULL;
		}
	}

	~adjacencyWDigraph2() {
		for (int i = 1; i <= n; i++) {      
			weightedEdge<T> *index1 = a[i], *index2;
			while (index1 != NULL) {
				index2 = index1->next;
				delete index1;
				index1 = index2;
			}
		}
		delete a;
	}

	int numberOfVertices() const { return n; }

	int numberOfEdges() const { return e; }

	bool directed() const { return true; }

	bool weighted() const { return true; }

	bool existsEdge(int i, int j) const {
		if (i < 1 || j < 1 || i > n || j > n)
			return false;
		weightedEdge<T> *index = a[i];
		while (index != NULL) {
			if (index->vertex2() == j) {
				return true;
			}
			index = index->next;
		}
		return false;
	}

	void insertEdge(weightedEdge<T> *theEdge) {
		int v1 = theEdge->vertex1();
		int v2 = theEdge->vertex2();
		if (v1 < 1 || v2 < 1 || v1 > n || v2 > n || v1 == v2){
			ostringstream s;
			s << "(" << v1 << "," << v2
				<< ") is not a permissible edge";
			cout << "����ı߲���ȷ��" << s.str();
			return;
		}

		if (a[v1] == NULL) {
			a[v1] = theEdge;
			a[v1]->next = NULL;
		}
		else {
			theEdge->next = a[v1];
			a[v1] = theEdge;
		}
		e++;
	}

	void eraseEdge(int i, int j) {
		if (i >= 1 && j >= 1 && i <= n && j <= n){
			weightedEdge<T> *cur = a[i], *pre=a[i];

			if (a[i]->vertex2() == j) {
				weightedEdge<T> *temp = a[i];
				a[i] = a[i]->next;
				delete temp;
				e--;
			}
			else {
				while (cur != NULL) {
					if (cur->vertex2() == j) {
						pre->next = cur->next;
						delete cur;
						e--;
						break;
					}
					pre = cur;
					cur = cur->next;
				}
			}
		}
	}

	void checkVertex(int theVertex) const {
		if (theVertex < 1 || theVertex > n)
		{
			ostringstream s;
			s << "no vertex " << theVertex;
			cout << "����Ķ��㲻�Ϸ���" << s.str();
			getchar();
		}
	}

	class myIterator{
	public:
		myIterator(weightedEdge<T> **a, int theRow) {
			currentVertex = a[theRow];
		}

		~myIterator() {}

		weightedEdge<T>* next() {
			while (currentVertex != NULL) {
				weightedEdge<T> *preVertex = currentVertex;
				currentVertex=currentVertex->next;
				return preVertex;
			}
			return NULL;
			
		}

	protected:
		weightedEdge<T> *currentVertex;     //��ǰ���
	};

	//���ڽӱ��ĳһ�����ɵ�������ע�⣺���������������������������
	myIterator* iterator(weightedEdge<T> **a, int theVertex)
	{
		checkVertex(theVertex);
		return new myIterator(a, theVertex);
	}

	int outDegree(int theVertex) const {
		checkVertex(theVertex);

		int sum = 0;
		weightedEdge<T> *index = a[theVertex];
		while (index != NULL) {
			sum++;
			index = index->next;
		}
		return sum;
	}

	void output(ostream& out) const {
		for (int i = 1; i <= n; i++)
		{
			weightedEdge<T> *index = a[i];
			if (index == NULL) {
				out << "NULL" << endl;
			}
			else {
				while (index != NULL) {
					index->output(out);
					index = index->next;
				}
				out << endl;
			}
		}
	}

	/***************************************
	ͼ�Ĺ�����������������ڶ������Ĳ�α���
	****************************************/
	vector<int> bfs(int sourceVertex) const{
		checkVertex(sourceVertex);

		queue<int> q;
		vector<int> result;
		bool *flag = new bool[n+1];
		for (int i = 1; i <= n; i++) {
			flag[i] = false;
		}
		q.push(sourceVertex);

		while (!q.empty()) {
			int temp = q.front();
			q.pop();
			if (!flag[temp]) {
				result.push_back(temp);
				flag[temp] = true;
			}
			
			weightedEdge<T> *index = a[temp];
			while ((index != NULL) && !flag[index->vertex2()] ) {
				q.push(index->vertex2());
				index = index->next;
			}
		}
		return result;
	}

	void dfs(int theRow, vector<int> &result, bool *flag) {
		weightedEdge<T> *root = a[theRow];
		if (root != NULL) {
			result.push_back(root->vertex1());
			flag[root->vertex1()] = true;

			weightedEdge<T> *index = root;
			while ((index != NULL) && (!flag[index->vertex2()])) {
				dfs(index->vertex2(), result, flag);
				index = index->next;
			}
		}
		else {
			result.push_back(theRow);
			flag[theRow] = true;
		}
	}

	/***************************************
	ͼ��������������������ڶ�������ǰ�����
	****************************************/
	vector<int> dfs(int sourceVertex) {
		vector<int> result;
		bool *flag = new bool[n + 1];
		for (int i = 1; i <= n; i++) {
			flag[i] = false;
		}
		dfs(sourceVertex, result, flag);
		return result;
	}
};

template <class T>
ostream& operator<<(ostream& out, const graph<T>& x) {
	x.output(out); return out;
}

void test_graph();