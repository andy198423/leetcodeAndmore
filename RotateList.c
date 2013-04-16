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
    ListNode *rotateRight(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(head==NULL || head->next==NULL) return head;
		ListNode* node=head;
		int n=0;
		while(node!=NULL){
		   node=node->next;
		   n++;
		}
		k=k%n; // k can be larger than n, keep rotating
		if(k==0) return head;
		ListNode* fast, *slow;
		fast=head;
		slow=head;
		int i=0;
		while(fast->next!=NULL && i<k) {
		   fast=fast->next;
		   i++;
		}
		while(fast->next!=NULL){
		   fast=fast->next;
		   slow=slow->next;
		}
		fast->next=head;
		head=slow->next;
		slow->next=NULL;
		return head;
    }
};