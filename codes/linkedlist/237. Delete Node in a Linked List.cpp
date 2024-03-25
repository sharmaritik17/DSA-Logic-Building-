class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* nextNodeToBeDeleted = node->next;
        node->next = nextNodeToBeDeleted->next;
        node->val = nextNodeToBeDeleted->val;
        nextNodeToBeDeleted->next = NULL;
    }
};