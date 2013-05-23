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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return buildTreeHelper(preorder.begin(),inorder.begin(),inorder.size());
    }
    
    TreeNode* buildTreeHelper(vector<int>::iterator preorder, vector<int>::iterator inorder, int n)
    {
        if(n==0) return NULL;
        vector<int>::iterator it=find(inorder,inorder+n,*preorder);
        int indx=it-inorder;
        TreeNode* node=new TreeNode(*it);
        node->left=buildTreeHelper(preorder+1,inorder, indx);
        node->right=buildTreeHelper(preorder+indx+1,inorder+indx+1,n-indx-1);
        return node;
    }
};