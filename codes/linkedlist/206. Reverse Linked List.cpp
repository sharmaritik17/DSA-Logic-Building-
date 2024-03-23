class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL) return head;
        
        ListNode *prev=NULL,*curr=head,*nextNode=NULL;
        while(curr){
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
};