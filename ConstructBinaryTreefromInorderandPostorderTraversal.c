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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return buildTreeHelper(inorder.begin(), postorder.begin(), inorder.size());
    }
    
    TreeNode *buildTreeHelper(vector<int>::iterator inorder, vector<int>::iterator postorder, int n)
    {
        if(n==0) return NULL;
        vector<int>::iterator it=find(inorder, inorder+n, *(postorder+n-1));
        int indx=it-inorder;
        TreeNode* node=new TreeNode(*it);
        node->left=buildTreeHelper(inorder,postorder,indx);
        node->right=buildTreeHelper(inorder+indx+1,postorder+indx,n-indx-1);
        return node;
    }
};