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
    ListNode *partition(ListNode *head, int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(head==NULL) return head;
		ListNode* prehead, *posthead, *pretail, *posttail,*curnode;
		curnode=head;
		prehead=NULL;
		pretail=NULL;
		posthead=NULL;
		posttail=NULL;
	
		while(curnode!=NULL){
		    if(curnode->val<x){
			   if(pretail==NULL){
			      prehead=curnode;
				  pretail=prehead;
			   }
			   else{
			      pretail->next=curnode;
				  pretail=pretail->next;
			   }
			}
			else{
			    if(posttail==NULL){
				   posthead=curnode;
				   posttail=posthead;
				}
				else{
				   posttail->next=curnode;
				   posttail=posttail->next;
				}
			}
			curnode=curnode->next;
		}
		if(pretail!=NULL) pretail->next=posthead; 
		if(posttail!=NULL) posttail->next=NULL;
		if(prehead==NULL) return posthead;
		return prehead;
    }
};