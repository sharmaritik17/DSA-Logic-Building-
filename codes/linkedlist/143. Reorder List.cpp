class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head) return;

        ListNode* slow = head, *fast = head, *curr = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        stack<ListNode*> addressPointers;
        while(slow) {
            addressPointers.push(slow);
            slow = slow->next;
        }

        ListNode* nextNode = NULL;
        while(!addressPointers.empty()) {
            ListNode* top = addressPointers.top();
            addressPointers.pop();
            if (top == curr) break;
            
            nextNode = curr->next;
            curr->next = top;
            top->next = nextNode;
            curr = nextNode;
        }
        curr->next = NULL;
    }
};

#define nul     NULL
class Solution {
    ListNode* reverse(ListNode *head) {
        if (!head) {
            return {};
        }
        ListNode *nextNode = nul, *prev = nul, *curr = head;
        while (curr) {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

public:
    void reorderList(ListNode* head) {
        if (!head) {
            return;
        }

        ListNode *slow = head, *fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }


        ListNode *newHead = reverse(slow->next);
        slow->next = nul;


        ListNode *t1 = nul, *t2 = nul;
        while (head && newHead) {
            t1 = head->next;
            t2 = newHead->next;
            head->next = newHead;
            newHead->next = t1;
            head = t1;
            newHead = t2;
        }

    }
};



