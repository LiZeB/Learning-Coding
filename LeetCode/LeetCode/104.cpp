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
	int maxDepth(TreeNode* root) {
		int depth = 0;
		if (root == NULL) {
			return 0;
		}

		return compute_depth(root);
	}

	int compute_depth(TreeNode *node) {
		if (node->left == NULL && node->right == NULL) {
			return 1;
		}
		int L_depth = 0, R_depth = 0;
		if (node->left != NULL) {
			L_depth = compute_depth(node->left);
		}
		if (node->right != NULL) {
			R_depth = compute_depth(node->right);
		}

		return L_depth >= R_depth ? 1 + L_depth : 1 + R_depth;
	}
};