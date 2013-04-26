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
    void recoverTree(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        TreeNode* first, *second, *prenode;
		first=NULL;
		second=NULL;
		prenode=NULL;
		recoverTreeHelper(root,prenode,first,second);
		swap(first->val,second->val);
    }
	//inorder tranversal, find the pair of numbers that are not in ascending order
	// reassigning pointer value, have to use reference in the function parameter declaration
	void recoverTreeHelper(TreeNode* curnode, TreeNode* &prenode, TreeNode* &first, TreeNode* &second){
	   if(curnode==NULL) return;
	   recoverTreeHelper(curnode->left, prenode, first, second);
	   if(prenode && prenode->val>curnode->val){
	      if(first==NULL) first=prenode;
		  second=curnode;
	   }
	   prenode=curnode;
	   recoverTreeHelper(curnode->right, prenode, first, second);
	}
};