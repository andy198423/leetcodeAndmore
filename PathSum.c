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
    bool hasPathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return hasPathSumHelper(root,sum);
    }
    
    bool hasPathSumHelper(TreeNode* root, int Sum)
    {
        if(root==NULL) return NULL;
        Sum-=root->val;
        if(root->left==NULL && root->right==NULL) return (Sum==0);
        return (hasPathSumHelper(root->left,Sum) || hasPathSumHelper(root->right,Sum));
    }
};