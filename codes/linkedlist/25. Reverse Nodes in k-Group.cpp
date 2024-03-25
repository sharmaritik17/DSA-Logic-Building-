class Solution {
    ListNode* reverse(ListNode* head, int k) {
        ListNode* nextNode = NULL, *prev = NULL, *curr = head;
        while (curr && k > 0) {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
            k--;
        }
        return prev;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k <= 1) return head;

        ListNode* newHead = NULL;
        ListNode* tail = NULL;
        ListNode* kHead = head;
        ListNode* curr = head;

        while (curr) {
            int count = 0;

            while (curr && count < k) {
                curr = curr->next;
                count++;
            }

            if (count == k) {
                ListNode* revHead = reverse(kHead, k);

                if (!newHead) {
                    newHead = revHead;
                }

                if (tail) {
                    tail->next = revHead;
                }

                tail = kHead;
                kHead = curr;
            }
        }

        if (tail) {
            tail->next = kHead;
        }

        return newHead ? newHead : head;
    }
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k <= 1|| !head){
            return head;
        }
        
        ListNode *curr = head,*nextNode = NULL,*prev=NULL;
        int count = 0;
        while(curr && count<k){
            count++;
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        
        if(count < k) return head;

        head->next = reverseKGroup(curr,k);

        return prev;
    }
};