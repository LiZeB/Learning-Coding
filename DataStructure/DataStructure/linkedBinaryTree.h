#include<iostream>
#include<string>

using namespace std;

/**********************************************************
����������Ľڵ�binaryTreenode
***********************************************************/
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


/************************************************************
���������
*************************************************************/
template<class T>
class linkedBinaryTree
{
public:
	linkedBinaryTree() { root = NULL; treeSize = 0; }
	~linkedBinaryTree() { erase(); };
	bool empty() const { return treeSize == 0; }
	int size() const { return treeSize; }
	T* rootElement() const;
	void makeTree(const T& element, linkedBinaryTree<T>&, linkedBinaryTree<T>&);

	void preOrder(void(*theVisit)(binaryTreenode<T>*)){
		visit = theVisit; 
		preOrder(root);
	}
	void inOrder(void(*theVisit)(binaryTreenode<T>*)){
		visit = theVisit; 
		inOrder(root);
	}
	void postOrder(void(*theVisit)(binaryTreenode<T>*)){
		visit = theVisit; 
		postOrder(root);
	}

	void levelOrder(void(*theVisit)(binaryTreenode<T> *)) {
		visit = theVisit; 
		levelOrder(root);
	}

	void erase(){
		postOrder(dispose);
		root = NULL;
		treeSize = 0;
	}
	
	int height() const { return height(root); }

protected:
	binaryTreenode<T> *root;                
	int treeSize;                         
	static void (*visit)(binaryTreenode<T>*);      // visitֻ��һ������ָ��
	
	void preOrder(binaryTreenode<T> *t);
	void inOrder(binaryTreenode<T> *t);
	void postOrder(binaryTreenode<T> *t);
	void levelOrder(binaryTreenode<T> *t);

	int height(binaryTreenode<T> *t) const;
};
template<class T>
void(*linkedBinaryTree<T>::visit)(binaryTreenode<int>*);
void(*linkedBinaryTree<pair<int, char> >::visit)(binaryTreenode<pair<int, char> >*);

template<class T>
void dispose(binaryTreenode<T> *t) {
	delete t;
}
template<class T>
void output(binaryTreenode<T> *t) {
	cout << t->element << ' ';
}


/**************************************************************
��linkedBinaryTree������ʵ��һ������������binarySearchTree
***************************************************************/
template<class K, class E>
class binarySearchTree : public linkedBinaryTree<pair<K, E>>
{
public:
	bool empty() const { return treeSize == 0; }
	int size() const { return treeSize; }
	pair<K, E>* find(K& theKey) const;
	void insert(const pair<K, E>& thePair);
	void erase(K& theKey);

	void ascend() { inOrder(output); }   //���ڶ����������˵�������о͸պ����������
};

void test_linkedBinaryTree();
void test_binarySearchTree();

