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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(l1==NULL) return l2;
		if(l2==NULL) return l1;
		if(l1==NULL && l2==NULL) return NULL;
		ListNode* head;
		if(l1->val<l2->val){
		   head=l1;
		   l1=l1->next;
		}
		else{
		   head=l2;
		   l2=l2->next;
		}
		ListNode* cur=head;
		while(l1!=NULL && l2!=NULL){
		   if(l1->val<l2->val){
		      cur->next=l1;
			  cur=cur->next;
			  l1=l1->next;
		   }
		   else{
		      cur->next=l2;
			  cur=cur->next;
			  l2=l2->next;
		   }
		}
		
		if(l1!=NULL) cur->next=l1;
		if(l2!=NULL) cur->next=l2;
		return head;
    }
};