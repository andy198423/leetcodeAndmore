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
    vector<vector<int> > levelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int>> results;
        vector<int> row;
        for(int height=1; height<=maxHeight(root); height++)
        {
            levelOrderHelper(root, height, row);
            results.push_back(row);
            row.clear();
        }
        return results;
    }
    
    int maxHeight(TreeNode* root)
    {
        if(root==NULL) return 0;
        return 1+max(maxHeight(root->left),maxHeight(root->right));
    }
    
    void levelOrderHelper(TreeNode* root, int height, vector<int>& row)
    {
        if(root==NULL || height==0) return;
        if(height==1) 
        {
            row.push_back(root->val);
        }
        levelOrderHelper(root->left,height-1, row);
        levelOrderHelper(root->right,height-1, row);
    }
};

class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int>> results;
        queue<TreeNode*> cur, next; 
        vector<int> row;
        if(root) cur.push(root);
        while(!cur.empty())
        {
            row.clear();
            while(!cur.empty())
            {
                TreeNode* node=cur.front();
                cur.pop();
                row.push_back(node->val);
                if(node->left) next.push(node->left);
                if(node->right) next.push(node->right);
            }
            swap(cur,next);
            results.push_back(row);
        }
        
        return results;
    }
};

class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int>> results;
        vector<int> row;
        int cur=1, next=0;
        queue<TreeNode*> curQ;
        if(root) curQ.push(root);
        while(!curQ.empty())
        {
            row.clear();
            while(cur!=0)
            {
                TreeNode* node=curQ.front();
                curQ.pop();
                cur--;
                row.push_back(node->val);
                if(node->left)
                {
                    curQ.push(node->left);
                    next++;
                }
                if(node->right)
                {
                    curQ.push(node->right);
                    next++;
                }
            }
            swap(cur,next);
            results.push_back(row);
        }
        return results;
    }
};