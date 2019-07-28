#include<iostream>
using namespace std;

template<class T>
struct binaryTreeNode {
	T element;
	binaryTreeNode<T> *leftChild, *rightChild;
	binaryTreeNode() { leftChild = rightChild = NULL; }
	binaryTreeNode(const T theElement) {
		element = theElement;
		leftChild = rightChild = NULL;
	}
	binaryTreeNode(const T theElement, binaryTreeNode *theLeftChild, binaryTreeNode *theRightChild) {
		element = theElement;
		leftChild = theLeftChild;
		rightChild = theRightChild;
	}
};

template<class T>
class binaryTree {
public:
	virtual ~binaryTree() {}
	virtual bool empty() const = 0;
	virtual int size() const = 0;
	virtual void preOrder(void (*) (T *)) = 0;
	virtual void inOrder(void (*) (T *)) = 0;
	virtual void postOrder(void (*) (T *)) = 0;
	//virtual void levelOrder(void(*) (T *)) = 0;

};


template<class T>
class linkedBinaryTree : public binaryTree<binaryTreeNode<T> >
{
public:
	linkedBinaryTree() { root = NULL; treeSize = 0; }
	~linkedBinaryTree() { erase(); };
	bool empty() const { return treeSize == 0; }
	int size() const { return treeSize; }
	T* rootElement() const;
	void makeTree(const T& element, linkedBinaryTree<T>&, linkedBinaryTree<T>&);
	void removeLeftSubtree();
	linkedBinaryTree<T>& removeRightSubtree();
	void preOrder(void(*theVisit)(binaryTreeNode<T>*))
	{
		visit = theVisit; preOrder(root);
	}
	void inOrder(void(*theVisit)(binaryTreeNode<T>*))
	{
		visit = theVisit; inOrder(root);
	}
	void postOrder(void(*theVisit)(binaryTreeNode<T>*))
	{
		visit = theVisit; postOrder(root);
	}

	//void levelOrder(void(*)(binaryTreeNode<T> *));
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
	binaryTreeNode<T> *root;                // pointer to root
	int treeSize;                           // number of nodes in tree
	static void (*visit)(binaryTreeNode<T>*);      // visit只是一个函数指针
	static int count;         // used to count nodes in a subtree
	static void preOrder(binaryTreeNode<T> *t);
	static void inOrder(binaryTreeNode<T> *t);
	static void postOrder(binaryTreeNode<T> *t);
	static void countNodes(binaryTreeNode<T> *t)
	{
		visit = addToCount;
		count = 0;
		preOrder(t);
	}
	static void dispose(binaryTreeNode<T> *t) { delete t; }
	static void output(binaryTreeNode<T> *t)
	{
		cout << t->element << ' ';
	}
	static void addToCount(binaryTreeNode<T> *t)
	{
		count++;
	}
	static int height(binaryTreeNode<T> *t);
};

template<class T>
void(*linkedBinaryTree<T>::visit)(binaryTreeNode<int>*);  //仔细琢磨这一行的作用