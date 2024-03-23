class Solution {
public:
    bool recursivelyCheck(ListNode* currentNode) {
        if(currentNode == NULL) return 1;

        bool isPalindrome = recursivelyCheck(currentNode->next);
        if(isPalindrome == false || currentNode->val != frontNode->val) return false;
        frontNode = frontNode->next;

        return true;
    }
    ListNode *frontNode;
    bool isPalindrome(ListNode* head) {
        frontNode = head;
        return recursivelyCheck(head);
    }
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* smallAns = reverseList(head->next);
        head->next->next = head->next;
        head->next = NULL;
        return smallAns;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* slow = head, *fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        slow = reverseList(slow);

        when(slow) {
            if(slow-> val != head->val) return false;
            slow = slow->next;
            head = head->next;
        }

        return true;
    }
};