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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(head==NULL) return NULL;
        ListNode *fast, *slow;
		fast=head;
		slow=head;
		int i=0;
		while(fast!=NULL && i<n){
           fast=fast->next;
		   i++;
		}
        if(fast==NULL){
          head=head->next;
		  delete slow;
		  return head;
		}		
		while(fast->next!=NULL){
		  fast=fast->next;
		  slow=slow->next;
		}
		ListNode *node=slow->next;
		slow->next=node->next;
		delete node;
		return head;
    }
};