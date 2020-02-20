/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.size() == 0) {
			return NULL;
		}

		int root_value = preorder[0];
		TreeNode *root = new TreeNode(root_value);
		int root_index = 0;
		for (auto val : inorder) {
			if (val == root_value) {
				break;
			}
			root_index++;
		}

		vector<int> preorder_left;
		for (int i = 1; i <= root_index; i++) {
			preorder_left.push_back(preorder[i]);
		}
		vector<int> inorder_left;
		for (int i = 0; i<root_index; i++) {
			inorder_left.push_back(inorder[i]);
		}

		vector<int> preorder_right;
		for (int i = 1 + root_index; i<preorder.size(); i++) {
			preorder_right.push_back(preorder[i]);
		}
		vector<int> inorder_right;
		for (int i = root_index + 1; i<inorder.size(); i++) {
			inorder_right.push_back(inorder[i]);
		}


		TreeNode *Left = buildTree(preorder_left, inorder_left);
		TreeNode *Right = buildTree(preorder_right, inorder_right);
		root->left = Left;
		root->right = Right;

		return root;
	}
};