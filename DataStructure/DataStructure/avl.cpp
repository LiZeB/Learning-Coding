#include "avl.h"

template<class T>
void avlBinaryTree<T>::insert(const T &x, avlNode<T> *t) {
	if (t == nullptr)
		t = new avlNode<T>(x, nullptr, nullptr);
	else if (x < t->element)
		insert(x, t->left);
	else if (x > t->elemet)
		insert(x, t->right);

	this->balance(t);
}

template<class T>
void avlBinaryTree<T>::balance(avlNode<T> *t) {
	if (t == nullptr)
		return;
	if ((t->left->height - t->right->height) > ALLOWED_IMBALANCE) {
		if (t->left->left->height >= t->left->right->height)
			rotatedWithLeftChild(t);
		else
			doubleWithLeftChild(t);
	}
	else if ((t->right->height - t->left->height) > ALLOWED_IMBALANCE) {
		if (t->right->right->height >= t->right->left)
			rotateWithRightChild(t);
		else
			doubleWithRightChild(t);
	}

	t->height = max(t->left->height, t->right->height) + 1;
}