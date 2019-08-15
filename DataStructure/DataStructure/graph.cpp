#include "graph.h"

void test_graph() {
	cout << "***********测试邻接矩阵表示的图*****************" << endl;
	adjacencyWDigraph<int> g(4);
	cout << "Number of Vertices = " << g.numberOfVertices() << endl;
	cout << "Number of Edges = " << g.numberOfEdges() << endl;

	g.insertEdge(new weightedEdge<int>(2, 4, 1));
	g.insertEdge(new weightedEdge<int>(1, 3, 2));
	g.insertEdge(new weightedEdge<int>(2, 1, 3));
	g.insertEdge(new weightedEdge<int>(1, 4, 4));
	g.insertEdge(new weightedEdge<int>(4, 2, 5));
	g.insertEdge(new weightedEdge<int>(4, 3, 6));
	cout << "The graph is" << endl;
	cout << "Number of Vertices = " << g.numberOfVertices() << endl;
	cout << "Number of Edges = " << g.numberOfEdges() << endl;
	cout << g << endl;

	g.eraseEdge(2, 1);
	cout << "The graph after deleting (2,1) is" << endl;
	cout << "Number of Vertices = " << g.numberOfVertices() << endl;
	cout << "Number of Edges = " << g.numberOfEdges() << endl;
	cout << g << endl;

	cout << "existsEdge(3,1) = " << g.existsEdge(3, 1) << endl;
	cout << "existsEdge(1,3) = " << g.existsEdge(1, 3) << endl;
	cout << "inDegree(3) = " << g.inDegree(3) << endl;
	cout << "outDegree(1) = " << g.outDegree(1) << endl;
	cout << "Number of Vertices = " << g.numberOfVertices() << endl;
	cout << "Number of Edges = " << g.numberOfEdges() << endl;

	cout << "Edges incident to vertex 4" << endl;
	vertexIterator<int>* gi = g.iterator(4);
	int temp;
	while (temp = gi->next())
		cout << temp << endl;

	cout << "***********测试邻接表表示的图*****************" << endl;
	adjacencyWDigraph2<int> g1(4);
	cout << "Number of Vertices = " << g1.numberOfVertices() << endl;
	cout << "Number of Edges = " << g1.numberOfEdges() << endl;

	g1.insertEdge(new weightedEdge<int>(2, 4, 1));
	g1.insertEdge(new weightedEdge<int>(1, 3, 2));
	g1.insertEdge(new weightedEdge<int>(2, 1, 3));
	g1.insertEdge(new weightedEdge<int>(1, 4, 4));
	g1.insertEdge(new weightedEdge<int>(4, 2, 5));
	cout << "The graph is" << endl;
	cout << "Number of Vertices = " << g1.numberOfVertices() << endl;
	cout << "Number of Edges = " << g1.numberOfEdges() << endl;
	cout << g1 << endl;

	g1.eraseEdge(2, 1);
	cout << "The graph after deleting (2,1) is" << endl;
	cout << "Number of Vertices = " << g1.numberOfVertices() << endl;
	cout << "Number of Edges = " << g1.numberOfEdges() << endl;
	cout << g1 << endl;

	cout << "existsEdge(3,1) = " << g1.existsEdge(3, 1) << endl;
	cout << "existsEdge(1,3) = " << g1.existsEdge(1, 3) << endl;
	cout << "outDegree(1) = " << g1.outDegree(1) << endl;
	cout << "Number of Vertices = " << g1.numberOfVertices() << endl;
	cout << "Number of Edges = " << g1.numberOfEdges() << endl;
}


