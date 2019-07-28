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

	left.root = right.root = NULL;   //��ϸ�����һ�е�����
	left.treeSize = right.treeSize = 0;
}

template<class E>
void linkedBinaryTree<E>::preOrder(binaryTreeNode<E> *t)
{
	/***********ǰ�����*************/
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
	/*********�������******************/
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
	/*************�������*****************/
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
	/***********��α���**********/
	queue<binaryTreeNode<T> *> q1;
	while (t != NULL) {
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
	}

}


template<class T>
int linkedBinaryTree<T>::height(binaryTreeNode<T> *t) const 
{
	/*****����ڵ�Ϊt�Ķ������ĸ߶�******/
	if (t == NULL)
		return 0;                    // empty tree
	int hl = height(t->leftChild);  // height of left
	int hr = height(t->rightChild); // height of right
	if (hl > hr)
		return ++hl;
	else
		return ++hr;
}

//template<class E>
//void linkedBinaryTree<E>::removeLeftSubtree()
//{
//	if (treeSize == 0)
//		exit(0);
//
//	linkedBinaryTree<E> leftSubtree;
//	leftSubtree.root = root->leftChild;
//	count = 0;
//	leftSubtree.treeSize = countNodes(leftSubtree.root);
//	root->leftChild = NULL;
//	treeSize -= leftSubtree.treeSize;
//
//}


