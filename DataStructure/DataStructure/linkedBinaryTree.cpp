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
	 combine left, right, and element to make new tree.
	 left, right, and this must be different trees.
	 create combined tree
	**************************************************/
	root = new binaryTreeNode<T>(element, left.root, right.root);
	treeSize = left.treeSize + right.treeSize + 1;

	left.root = right.root = NULL;   //仔细体会这一行的意义
	left.treeSize = right.treeSize = 0;
}

template<class E>
void linkedBinaryTree<E>::preOrder(binaryTreeNode<E> *t)
{
	/***********前序遍历*************/
	if (t != NULL)
	{
		linkedBinaryTree<E>::visit(t);
		preOrder(t->leftChild);
		preOrder(t->rightChild);
	}
}

template<class E>
void linkedBinaryTree<E>::inOrder(binaryTreeNode<E> *t)
{
	/*********中序遍历******************/
	if (t != NULL)
	{
		inOrder(t->leftChild);
		linkedBinaryTree<E>::visit(t);
		inOrder(t->rightChild);
	}
}

template<class E>
void linkedBinaryTree<E>::postOrder(binaryTreeNode<E> *t)
{
	/*************后序遍历*****************/
	if (t != NULL)
	{
		postOrder(t->leftChild);
		postOrder(t->rightChild);
		linkedBinaryTree<E>::visit(t);
	}
}

template<class T>
void linkedBinaryTree<T>::levelOrder(binaryTreeNode<T> *t)
{
	/***********************************************
	层次遍历:这里写了两种层次遍历的方式，
	第二种方式更方便理解，也更适宜在层次遍历时，
	对同一层元素施加扩展操作
	***********************************************/
	queue<binaryTreeNode<T> *> q1;
	/*while (t != NULL) {
		linkedBinaryTree<T>::visit(t);
		if(t->leftChild != NULL)
			q1.push(t->leftChild);
		if(t->rightChild != NULL)
			q1.push(t->rightChild);
		if (!q1.empty()) {
			t = q1.front();
			q1.pop();
		}
		else {
			return;
		}
	}*/
	q1.push(t);
	binaryTreeNode<T> *t1;
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
int linkedBinaryTree<T>::height(binaryTreeNode<T> *t) const 
{
	/*****求根节点为t的二叉树的高度******/
	if (t == NULL)
		return 0;                    // empty tree
	int hl = height(t->leftChild);  // height of left
	int hr = height(t->rightChild); // height of right
	if (hl > hr)
		return ++hl;
	else
		return ++hr;
}

template<class K, class E>
pair<K, E>* binarySearchTree<K, E>::find(K& theKey) const
{
	/*********************************
	Return pointer to matching pair.
	Return NULL if no matching pair.
	p starts at the root and moves through
	the tree looking for an element with key theKey
	***********************************/
	binaryTreeNode<pair<K, E> > *p = root;
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
	Insert thePair into the tree. Overwrite existing
	pair, if any, with same key.
	find place to insert
	**********************************************/
	binaryTreeNode<pair<K, E> > *p = root, *pp = NULL;
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

	binaryTreeNode<pair<K, E> > *newNode
		= new binaryTreeNode<pair<K, E> >(thePair);
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
	binaryTreeNode<pair<K, E> > *p = root, *pp = NULL;
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
		binaryTreeNode<pair<K, E> > *s = p->leftChild, *ps = p;
		//要把左子树的右子树放到上面去
		while (s->rightChild != NULL)
		{
			ps = s;
			s = s->rightChild;
		}


		binaryTreeNode<pair<K, E> > *q =
			new binaryTreeNode<pair<K, E> >
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
	binaryTreeNode<pair<K, E> > *c;
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
