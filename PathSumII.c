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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int>> results;
        vector<int> path;
        pathSumHelper(root,sum,path,results);
        return results;
    }
    
    void pathSumHelper(TreeNode* root, int sum, vector<int> path, vector<vector<int>> & results)
    {
        if(root==NULL) return;
        sum-=root->val;
        path.push_back(root->val);
        if(sum==0 && root->left==NULL && root->right==NULL)
        {
            results.push_back(path);
            return;
        }
        pathSumHelper(root->left,sum,path,results);
        pathSumHelper(root->right,sum,path,results);
    }
};