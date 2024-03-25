class Solution {
    ListNode *omitNodes(ListNode *slow, ListNode *fast) {
        while (fast != slow) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return omitNodes(head, fast);
            }
        }
        return {};
    }
};

/*            l2
  l1      6 7 8 
1 2 3 4 5       9
          2 5 3 
          
slow = l1 + l2
fast = l1+l2 + nC
          2slow = fast
          l1 + l2 = nc
          l1 = nC-l2
          Thus we can say that the distance of head to collision inside the loop is the same as the collision to start point of the loop.
*/


class Solution {
    ListNode *omitNodes(ListNode *slow, ListNode *fast , int count) {
        for (int i = 0; i < count; i++) {
            fast = fast->next;
        }

        while (fast != slow) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
    int countNodesInCycle(ListNode *head, ListNode *&save) {
        int count = 1;
        head = head->next;
        while (head != save) {
            head = head->next;
            count++;
        }
        return count;
    }
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                int count = countNodesInCycle(slow, slow);
                return omitNodes(head, head, count);
            }
        }
        return {};
    }
};