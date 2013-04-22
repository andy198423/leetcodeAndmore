/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return isValidBSThelper(root, INT_MIN, INT_MAX);
    }
	//preorder comparison 
	bool isValidBSThelper(TreeNode* root, int min, int max){
	   if(root==NULL) return true;
	   if(root->val > min && root->val < max){
	      return (isValidBSThelper(root->left, min, root->val) && isValidBSThelper(root->right, root->val, max));
	   }
	   return false;
	}
};