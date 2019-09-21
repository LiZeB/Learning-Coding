#include<iostream>
#include<string>
#include<vector>
#include <queue>

using namespace std;

struct binaryTreeNode {
	int element;
	binaryTreeNode *leftChild, *rightChild;
	binaryTreeNode() { leftChild = rightChild = NULL; }
	binaryTreeNode(const int theElement) {
		element = theElement;
		leftChild = rightChild = NULL;
	}
	binaryTreeNode(const int theElement, binaryTreeNode *theLeftChild, binaryTreeNode *theRightChild) {
		element = theElement;
		leftChild = theLeftChild;
		rightChild = theRightChild;
	}
};

class binaryTree {
public:
	binaryTree() { root = NULL; }
	void makeTree_pre();
	void makeTree_level();
	void pre_order();
	void in_order();
	void post_order();
	void level_order();

private:
	binaryTreeNode *root;
	void makeTree_pre(binaryTreeNode* &);   //因为这里的一个小引用符号，调试很长时间
	void makeTree_level(binaryTreeNode * &, queue<binaryTreeNode *>&);
	void pre_order(binaryTreeNode *);
	void in_order(binaryTreeNode *);
	void post_order(binaryTreeNode *);
	void level_order(binaryTreeNode *);
};

void test_binaryTree();

//void binaryTree::makeTree_pre() {
//	makeTree_pre(root);
//}
//
//void binaryTree::makeTree_pre(binaryTreeNode* &index)
//{
//	string temp;
//	cin >> temp;
//	if (temp != "#") {
//		index = new binaryTreeNode(stoi(temp));
//		makeTree_pre(index->leftChild);
//		makeTree_pre(index->rightChild);
//	}
//}
//
///**********************************************************************
//一道笔试题：现输入二叉树层次遍历序列，请输出其前序遍历序列
//输入是层次遍历序列：0 1 2 3 # # 4 # 5 6 #，其中#代表该子节点不存在；
//输出是前序遍历序列为：0 1 3 # 5 # # # 2 # 4 6 # # #
//以上是原题，但是如果按原题这种层次遍历输入，下面的程序还不能正常处理，
//原因是最后一层5 6存在于队列时，不能结束循环，得再为每个节点增加两个# #结束；
//这个如果按原题输入来，应该是不能完成的
//***********************************************************************/
//void binaryTree::makeTree_level() {
//	queue<binaryTreeNode *> q1;
//	makeTree_level(root, q1);
//}
//
//void binaryTree::makeTree_level(binaryTreeNode * &index, queue<binaryTreeNode*> &q1) {
//	string temp;
//	cin >> temp;
//	binaryTreeNode *index1;
//	if (temp != "#") {
//		index = new binaryTreeNode(stoi(temp));
//		q1.push(index);
//	}
//	while (!q1.empty()) {
//		int width = q1.size();
//		for (int i = 0; i < width; i++) {
//			binaryTreeNode *temp1 = q1.front();
//			q1.pop();
//			cin >> temp;
//			if (temp != "#") {
//				temp1->leftChild = new binaryTreeNode(stoi(temp));
//				q1.push(temp1->leftChild);
//			}
//			cin >> temp;
//			if (temp != "#") {
//				temp1->rightChild = new binaryTreeNode(stoi(temp));
//				q1.push(temp1->rightChild);
//			}
//		}
//	}
//
//}
//
//void binaryTree::pre_order() {
//	this->pre_order(root);
//	cout << endl;
//}
//
//void binaryTree::pre_order(binaryTreeNode *index) {
//	if (index != NULL) {
//		cout << index->element << " ";
//		pre_order(index->leftChild);
//		pre_order(index->rightChild);
//	}
//	//为得到笔试题输出增加的，#代表不存在
//	else {
//		cout << "#" << " ";
//	}
//}
//
//void binaryTree::in_order() {
//	in_order(root);
//	cout << endl;
//}
//
//void binaryTree::in_order(binaryTreeNode *index) {
//	if (index != NULL) {
//		in_order(index->leftChild);
//		cout << index->element << " ";
//		in_order(index->rightChild);
//	}
//}
//
//void binaryTree::post_order() {
//	post_order(root);
//	cout << endl;
//}
//
//void binaryTree::post_order(binaryTreeNode *index) {
//	if (index != NULL) {
//		post_order(index->leftChild);
//		post_order(index->rightChild);
//		cout << index->element << " ";
//	}
//}
//
//void binaryTree::level_order() {
//	level_order(root);
//	cout << endl;
//}
//
//void binaryTree::level_order(binaryTreeNode *index) {
//	queue<binaryTreeNode *> q1;
//	if (index == NULL) {
//		return;
//	}
//	q1.push(index);
//	while (!q1.empty()) {
//		int width = q1.size();
//		for (int i = 0; i < width; i++) {
//			binaryTreeNode *temp = q1.front();
//			q1.pop();
//			cout << temp->element << " ";
//			if (temp->leftChild != NULL) q1.push(temp->leftChild);
//			if (temp->rightChild != NULL) q1.push(temp->rightChild);
//
//		}
//	}
//}
//
//void test_binaryTree() {
//	binaryTree tree;
//	tree.makeTree_level();
//	cout << "前序遍历" << endl;
//	tree.pre_order();
//	cout << "中序遍历" << endl;
//	tree.in_order();
//	cout << "后序遍历" << endl;
//	tree.post_order();
//	cout << "层次遍历" << endl;
//	tree.level_order();
//
//	system("pause");
//}