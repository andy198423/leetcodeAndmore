/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(head==NULL) return NULL;
		//if(head->next==NULL) return head;
		ListNode* prev, *cur;
		prev=head;
		cur=head->next;
		while(cur!=NULL){
		  if(prev->val==cur->val){
		    ListNode* node=cur;
			prev->next=node->next;
			cur=prev->next;
			delete node;
		  }
		  else{
		    prev=cur;
			cur=cur->next;
		  }
		}
		return head;
    }
};