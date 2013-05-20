/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode *sortedListToBST(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (head==NULL) return NULL;
        ListNode* node=head;
        int len=1;
        while((node=node->next)!=NULL) len++;
        return sortedListToBSTHelper(head, 0,len-1);
    }
    
    TreeNode* sortedListToBSTHelper(ListNode *&head, int start, int end)
    {
        if(start>end) return NULL;
        int mid=start+(end-start)/2;
        TreeNode *leftnode=sortedListToBSTHelper(head,start,mid-1);
        TreeNode *node=new TreeNode(head->val);
        head=head->next;
        node->left=leftnode;
        node->right=sortedListToBSTHelper(head,mid+1,end);
        return node;
    }
};