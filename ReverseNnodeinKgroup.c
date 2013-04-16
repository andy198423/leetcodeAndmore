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
    ListNode *reverseKGroup(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(head==NULL) return NULL;
		if(k<2) return head;
		int len=0;
		ListNode* node=head;
		while(node!=NULL){
		   node=node->next;
		   len++;
		}
		return reverseHelper(head,k,len);
    }
	
	ListNode* reverseHelper(ListNode* head, int k, int n){
	    if(n<k) return head;
		ListNode* prenode, *curnode, *nextnode, *nodetail;
		prenode=NULL;
		curnode=head;
		nodetail=head;
		for(int i=0; i<k; i++){
		   nextnode=curnode->next;
		   curnode->next=prenode;
		   prenode=curnode;
		   curnode=nextnode;
		}
		
		nodetail->next=reverseHelper(curnode,k,n-k);
		
		return prenode;
	}
	
};

// iterative solution
class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(k<2) return head;
		if(head==NULL) return NULL;
		ListNode* node=head;
		int len=0;
		while(node!=NULL){
		   node=node->next;
		   len++;
		}
		if(len<k) return head;
		int n=len/k;
		ListNode* prenode, *curnode, *nextnode, *curtail, *pretail, *curhead;
		prenode=NULL;
		curnode=head;
		pretail=NULL;
		for(int i=0; i<n; i++){
		   for(int j=0; j<k; j++){
		      nextnode=curnode->next;
			  curnode->next=prenode;
			  prenode=curnode;
			  curnode=nextnode;
			  if(j==0) curtail=prenode;
			  if(j==(k-1)) curhead=prenode;
		   }
		   if(pretail==NULL) head=curhead;
		   else pretail->next=curhead;
		   pretail=curtail;
		}
		curtail->next=curnode;
		return head;
		
    }
};


