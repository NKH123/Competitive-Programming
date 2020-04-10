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
    ListNode* middleNode(ListNode* head) {
    	int n=0;
    	ListNode* H=head;
    	while(H!=NULL){
    		H=H->next;
    		n++;
    	}
    	int mid=n/2;
    	H=head;
    	int ct=0;
    	while(ct<mid){
    		H=H->next;
    		ct++;
    	}
    	return H;
    }
};