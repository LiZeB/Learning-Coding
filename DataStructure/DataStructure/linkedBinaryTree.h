#include<iostream>
#include<string>
using namespace std;

class queueEmpty
{
public:
	queueEmpty(string theMessage =
		"Invalid operation on empty queue")
	{
		message = theMessage;
	}
	void outputMessage() { cout << message << endl; }
private:
	string message;
};

template<class T>
struct binaryTreenode {
	T element;
	binaryTreenode<T> *leftChild, *rightChild;
	binaryTreenode() { leftChild = rightChild = NULL; }
	binaryTreenode(const T theElement) {
		element = theElement;
		leftChild = rightChild = NULL;
	}
	binaryTreenode(const T theElement, binaryTreenode *theLeftChild, binaryTreenode *theRightChild) {
		element = theElement;
		leftChild = theLeftChild;
		rightChild = theRightChild;
	}
};

template<class T>
class binarytree {
public:
	virtual ~binarytree() {}
	virtual bool empty() const = 0;
	virtual int size() const = 0;
	virtual void preOrder(void (*) (T *)) = 0;
	virtual void inOrder(void (*) (T *)) = 0;
	virtual void postOrder(void (*) (T *)) = 0;
	virtual void levelOrder(void(*) (T *)) = 0;

};


template<class T>
class linkedBinaryTree : public binarytree<binaryTreenode<T> >
{
public:
	linkedBinaryTree() { root = NULL; treeSize = 0; }
	~linkedBinaryTree() { erase(); };
	bool empty() const { return treeSize == 0; }
	int size() const { return treeSize; }
	T* rootElement() const;
	void makeTree(const T& element, linkedBinaryTree<T>&, linkedBinaryTree<T>&);
	void preOrder(void(*theVisit)(binaryTreenode<T>*))
	{
		visit = theVisit; preOrder(root);
	}
	void inOrder(void(*theVisit)(binaryTreenode<T>*))
	{
		visit = theVisit; inOrder(root);
	}
	void postOrder(void(*theVisit)(binaryTreenode<T>*))
	{
		visit = theVisit; postOrder(root);
	}

	void levelOrder(void(*theVisit)(binaryTreenode<T> *)) {
		visit = theVisit; levelOrder(root);
	}
	void preOrderOutput() { preOrder(output); cout << endl; }
	void inOrderOutput() { inOrder(output); cout << endl; }
	void postOrderOutput() { postOrder(output); cout << endl; }
	void levelOrderOutput() { levelOrder(output); cout << endl; }

	void erase()
	{
		postOrder(dispose);
		root = NULL;
		treeSize = 0;
	}
	int height() const { return height(root); }

protected:
	binaryTreenode<T> *root;                // pointer to root
	int treeSize;                           // number of nodes in tree
	static void (*visit)(binaryTreenode<T>*);      // visit只是一个函数指针
	static int count;         // used to count nodes in a subtree
	static void preOrder(binaryTreenode<T> *t);
	static void inOrder(binaryTreenode<T> *t);
	static void postOrder(binaryTreenode<T> *t);
	static void levelOrder(binaryTreenode<T> *t);

	static void countNodes(binaryTreenode<T> *t)
	{
		visit = addToCount;
		count = 0;
		preOrder(t);
	}
	static void dispose(binaryTreenode<T> *t) { delete t; }
	static void output(binaryTreenode<T> *t)
	{
		cout << t->element << ' ';
	}
	static void addToCount(binaryTreenode<T> *t)
	{
		count++;
	}
	static int height(binaryTreenode<T> *t);
};

template<class T>
void(*linkedBinaryTree<T>::visit)(binaryTreenode<int>*);  //仔细琢磨这一行的作用
void(*linkedBinaryTree<pair<int, char> >::visit)(binaryTreenode<pair<int, char> >*);

template<class K, class E>
class binarySearchTree : public linkedBinaryTree<pair<K, E>>
{
public:
	bool empty() const { return treeSize == 0; }
	int size() const { return treeSize; }
	pair<K, E>* find(K& theKey) const;
	void insert(const pair<K, E>& thePair);
	void erase(K& theKey);

	void ascend() { inOrderOutput(); }
};


