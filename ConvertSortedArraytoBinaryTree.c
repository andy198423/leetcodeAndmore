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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		int ind=0;
	    return inorderHelper(num,0,num.size()-1,ind);
        //return preorderHelper(num,0,num.size()-1);
    }
	
	TreeNode *preorderHelper(vector<int> &num, int start, int end) 
	{
	    if(start>end) return NULL;
		int mid=start+(end-start)/2;
		TreeNode* node=new TreeNode(num[mid]);
		node->left=preorderHelper(num,start,mid-1);
		node->right=preorderHelper(num,mid+1,end);
		return node;
	}
	
	TreeNode *inorderHelper(vector<int> &num, int start, int end, int& ind)
	{
	    if(start>end) return NULL;
		int mid=start+(end-start)/2;
		TreeNode* left=inorderHelper(num,start,mid-1,ind);
		TreeNode* node=new TreeNode(num[ind++]);
		node->left=left;
		node->right=inorderHelper(num,mid+1,end,ind);
		return node;
	}
};