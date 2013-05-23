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
    void flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        TreeNode * result=NULL;
        flattenHelper(root,result);
    }
    
    void flattenHelper(TreeNode* node, TreeNode*& result)
    {
        if(node==NULL) return;
        TreeNode* left=node->left;
        node->left=NULL;
        TreeNode* right=node->right;
        node->right=NULL;
        if(result==NULL) result=node;
        else result->right=node, result=result->right;
        flattenHelper(left,result);
        flattenHelper(right,result);
    }
};


class Solution {
public:
    void flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root==NULL) return;
        TreeNode* result=NULL;
        stack<TreeNode*> nodestk;
        nodestk.push(root);
        while(!nodestk.empty())
        {
            TreeNode* node=nodestk.top();
            nodestk.pop();
            if(node->right) nodestk.push(node->right), node->right=NULL;
            if(node->left) nodestk.push(node->left), node->left=NULL;
            if(result==NULL) result=node;
            else result->right=node, result=result->right;
        }
        
    }
};
