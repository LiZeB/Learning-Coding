#include <iostream>

using namespace std;

template<class T>
class avlNode {
public:
	T element;
	avlNode<T> *left;
	avlNode<T> *right;
	int height;
public:
	avlNode(const T &ele, avlNode<T> *lt, avlNode<T> *rt, int h = 0) :element(ele), left(lt), right(rt), height(h) {}

};

template<class T>
class avlBinaryTree {
public:
	avlBinaryTree() { root = NULL; height = 0; }
	void insert(const T &x, avlNode<T> &t);
	void balance(avlNode<T> *t);
	void remove(const T &x, avlNode<T> &t);
public:
	avlNode<T> *root;
	int height;
private:
	static int ALLOWED_IMBALANCE = 1;
	void rotatedWithLeftChild(avlNode<T> &k2);
	void doubleWithLeftChild(avlNode<T> &k3);
};

template<class T>
static int avlBinaryTree<T>::ALLOWED_IMBALANCE;