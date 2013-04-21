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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(head==NULL || head->next==NULL) return head;
		ListNode* pretail, *revtail, *nextnode, *prenode,* curnode;
		curnode=head;
		prenode=NULL;
		pretail=NULL;
		for(int i=1; i<=n; i++){
		   if(i==(m-1)) pretail=curnode;
		   if(i==m) revtail=curnode;
		   if(i>=m){
		      nextnode=curnode->next;
			  curnode->next=prenode;
			  prenode=curnode;
			  curnode=nextnode;
		   }
		   else curnode=curnode->next;
		}
		if(pretail==NULL) head=prenode;
        else pretail->next=prenode;
        revtail->next=curnode;
        return head;		
    }
};