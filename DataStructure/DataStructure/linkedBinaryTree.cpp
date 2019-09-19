#include <queue>
#include "linkedBinaryTree.h"

template<class T>
T* linkedBinaryTree<T>::rootElement() const {
	return root->element;
}

template<class T>
void linkedBinaryTree<T>::makeTree(const T& element,
	linkedBinaryTree<T>& left, linkedBinaryTree<T>& right)
{
	/*************************************************
	根据左右两棵子树构建一棵新树
	**************************************************/
	root = new binaryTreenode<T>(element, left.root, right.root);
	treeSize = left.treeSize + right.treeSize + 1;

	left.root = right.root = NULL;   //仔细体会这一行的意义
	left.treeSize = right.treeSize = 0;
}

template<class E>
void linkedBinaryTree<E>::preOrder(binaryTreenode<E> *t)
{
	if (t != NULL)
	{
		linkedBinaryTree<E>::visit(t);
		preOrder(t->leftChild);
		preOrder(t->rightChild);
	}
}

template<class E>
void linkedBinaryTree<E>::inOrder(binaryTreenode<E> *t)
{
	if (t != NULL)
	{
		inOrder(t->leftChild);
		linkedBinaryTree<E>::visit(t);
		inOrder(t->rightChild);
	}
}

template<class E>
void linkedBinaryTree<E>::postOrder(binaryTreenode<E> *t)
{
	if (t != NULL)
	{
		postOrder(t->leftChild);
		postOrder(t->rightChild);
		linkedBinaryTree<E>::visit(t);
	}
}

template<class T>
void linkedBinaryTree<T>::levelOrder(binaryTreenode<T> *t)
{
	queue<binaryTreenode<T>* > q1;
	if(t != NULL)
		q1.push(t);
	binaryTreenode<T> *t1;
	while (!q1.empty()) {
		int width = q1.size();
		for (int i = 0; i < width; i++) {
			t1 = q1.front();
			linkedBinaryTree<T>::visit(t1);
			q1.pop();
			if (t1->leftChild != NULL) q1.push(t1->leftChild);
			if (t1->rightChild != NULL) q1.push(t1->rightChild);
		}
	}

}

template<class T>
int linkedBinaryTree<T>::height(binaryTreenode<T> *t) const 
{
	/********************************************
	求根节点为t的二叉树的高度：这里采用的是递归
	的方法；
	*********************************************/
	if (t == NULL)
		return 0;                    
	int hl = height(t->leftChild);  
	int hr = height(t->rightChild); 
	if (hl > hr)
		return ++hl;
	else
		return ++hr;
}

template<class K, class E>
pair<K, E>* binarySearchTree<K, E>::find(K& theKey) const
{
	/****************************************
	二叉树查找：theKey代表要查找节点的关键字
	*****************************************/
	binaryTreenode<pair<K, E>> *p = root;
	while (p != NULL) {
		if (theKey < p->element.first)
			p = p->leftChild;
		else
			if (theKey > p->element.first)
				p = p->rightChild;
			else
				return &p->element;
	}

	return NULL;
}

template<class K, class E>
void binarySearchTree<K, E>::insert(const pair<K, E>& thePair)
{ 
	/*********************************************
	二叉查找树的插入
	**********************************************/
	binaryTreenode<pair<K, E> > *p = root, *pp = NULL;
	while (p != NULL)
	{
		pp = p;
		if (thePair.first < p->element.first)
			p = p->leftChild;
		else
			if (thePair.first > p->element.first)
				p = p->rightChild;
			else
			{
				p->element.second = thePair.second;
				return;
			}
	}

	binaryTreenode<pair<K, E> > *newNode
		= new binaryTreenode<pair<K, E> >(thePair);
	if (root != NULL)
		if (thePair.first < pp->element.first)
			pp->leftChild = newNode;
		else
			pp->rightChild = newNode;
	else
		root = newNode;
	treeSize++;
}

template<class K, class E>
void binarySearchTree<K, E>::erase(K& theKey)
{
	binaryTreenode<pair<K, E> > *p = root, *pp = NULL;
    // 先找到关键字theKey应该出现的位置
	while (p != NULL && p->element.first != theKey)
	{
		pp = p;
		if (theKey < p->element.first)
			p = p->leftChild;
		else
			p = p->rightChild;
	}
	//树中不存在theKey关键字
	if (p == NULL)
		return; 
	//树中存在关键字为theKey的元素，当这个元素的左右子树不为空时
	if (p->leftChild != NULL && p->rightChild != NULL)
	{
		binaryTreenode<pair<K, E> > *s = p->leftChild, *ps = p;
		//要把左子树的右子树放到上面去
		while (s->rightChild != NULL)
		{
			ps = s;
			s = s->rightChild;
		}


		binaryTreenode<pair<K, E> > *q =
			new binaryTreenode<pair<K, E> >
			(s->element, p->leftChild, p->rightChild);
		//要把左子树的右子树放到上面去，又分为放的是顶点位置还是非顶点位置
		if (pp == NULL)
			root = q;
		else if (p == pp->leftChild)
			pp->leftChild = q;
		else
			pp->rightChild = q;

		if (ps == p) pp = q;
		else pp = ps;
		delete p;
		p = s;
	}
	//如何处理被删除节点的左子树
	binaryTreenode<pair<K, E> > *c;
	if (p->leftChild != NULL)
		c = p->leftChild;
	else
		c = p->rightChild;

	if (p == root)
		root = c;
	else
	{
		if (p == pp->leftChild)
			pp->leftChild = c;
		else pp->rightChild = c;
	}
	treeSize--;
	delete p;
}

template <class K, class E>
ostream& operator<<(ostream& out, const pair<K, E>& x)
{
	out << x.first << ' ' << x.second; 
	return out;
}

void test_linkedBinaryTree() {
	linkedBinaryTree<int> a, x, y, z;
	y.makeTree(1, a, a);
	z.makeTree(2, a, a);
	x.makeTree(3, y, z);
	y.makeTree(4, x, a);
	cout << "节点个数 = ";
	cout << y.size() << endl;
	cout << "height = ";
	cout << y.height() << endl;
	cout << "前序遍历： ";
	y.preOrder(output);
	cout << endl;
	cout << "中序遍历： ";
	y.inOrder(output);
	cout << endl;
	cout << "后序遍历： ";
	y.postOrder(output);
	cout << endl;
	cout << "层次遍历： ";
	y.levelOrder(output);
	cout << endl;
	cout << "删除二叉树";
	y.erase();
	cout <<endl;
}

void test_binarySearchTree() {
	binarySearchTree<int, char> y1;
	y1.insert(pair<int, char>(1, 'a'));
	y1.insert(pair<int, char>(6, 'c'));
	y1.insert(pair<int, char>(4, 'b'));
	y1.insert(pair<int, char>(8, 'd'));
	y1.insert(pair<int, char>(7, 'f'));
	cout << "Tree size is " << y1.size() << endl;
	y1.ascend();
	cout << endl;

	int a_1 = 4;
	y1.erase(a_1);
	cout << "Tree size is " << y1.size() << endl;
	y1.ascend();
	cout << endl;
}