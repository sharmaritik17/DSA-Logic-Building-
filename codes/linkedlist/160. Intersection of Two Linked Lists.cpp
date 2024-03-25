class Solution {
public:
	ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
		if (!head1 || !head2)
			return NULL;

		ListNode *a = head1;
		ListNode *b = head2;

		while (a != b) {
			a = a == NULL ? head2 : a->next;
			b = b == NULL ? head1 : b->next;
		}

		return a; 
	}
};
