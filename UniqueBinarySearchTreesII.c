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
    vector<TreeNode *> generateTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return generateTreesHelper(1,n);
    }
    
    vector<TreeNode*> generateTreesHelper(int left, int right)
    {
        vector<TreeNode*> nodes;
        if(left>right)
        {
            nodes.push_back(NULL);
            return nodes;
        }
        
        for(int k=left; k<=right; k++)
        {
            vector<TreeNode*> leftnodes=generateTreesHelper(left,k-1);
            vector<TreeNode*> rightnodes=generateTreesHelper(k+1,right);
            for(int i=0; i<leftnodes.size();i++)
            {
                for(int j=0; j<rightnodes.size(); j++)
                {
                    TreeNode* node=new TreeNode(k);
                    node->left=leftnodes[i];
                    node->right=rightnodes[j];
                    nodes.push_back(node);
                }
            }
        }
        
        return nodes;
    }
};