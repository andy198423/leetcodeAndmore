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
    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> result;
        stack<TreeNode*> holder;
        TreeNode* cur=root;
        while(!holder.empty() || cur!=NULL)
        {
            if(cur!=NULL)
            {
                holder.push(cur);
                cur=cur->left;
            }
            else
            {
                cur=holder.top();
                holder.pop();
                result.push_back(cur->val);
                cur=cur->right;
            }
        }
        
        return result;
    }
};