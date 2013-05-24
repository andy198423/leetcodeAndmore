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
    int maxPathSum(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int MaxSum=root->val;
        maxPathSumHelper(root,MaxSum);
        return MaxSum;
    }
    
    int maxPathSumHelper(TreeNode* node, int& MaxSum)
    {
        if(node==NULL) return 0;
        int leftMax=maxPathSumHelper(node->left,MaxSum);
        int rightMax=maxPathSumHelper(node->right,MaxSum);
        int maxPath=node->val;
        if(leftMax>0) maxPath+=leftMax;
        if(rightMax>0) maxPath+=rightMax;
        if(maxPath>MaxSum) MaxSum=maxPath;
        int res=node->val;
        return max(res,res+max(leftMax,rightMax));
    }
};