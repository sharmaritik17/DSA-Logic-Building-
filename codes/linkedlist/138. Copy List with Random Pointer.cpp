#include<unordered_map>
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> ump;
        if (!head)
            return head;

        Node *temp = head;
        Node *newHead = NULL;
        
        while (temp) {
            Node *newlist = new Node(temp->val);
            if (!newHead) {
                newHead = newlist;
            }
            ump[temp] = newlist;
            temp = temp->next;
        }

        Node *curr = head;
        while (curr) {
            Node *save = ump[curr];
            save->next = ump[curr->next];
            save->random = ump[curr->random];

            curr = curr->next;
        }

        return newHead;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // Create a clone linked list on the fly, weaving it with the original linked list, while also catering to next pointers.
        // Assign the random pointers of the clone linked list with the help of the original's random pointers.
        // Unweave the original linked list and the clone linked list, separating them.
        // Return the clone linked list.

        // Step 1: Create a clone linked list by weaving it with the original linked list
        Node *curr = head;
        while(curr) {
            Node *newNode = new Node(curr->val);
            newNode->next = curr->next;
            curr->next = newNode;

            curr = newNode->next;
        }

        // Step 2: Assign random pointers for the clone linked list based on the original linked list's random pointers
        curr = head;
        while(curr && curr->next) {
            if(curr->random) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        // Step 3: Unweave the original and clone linked lists
        Node *newHead = NULL, *tail = NULL;
        curr = head;
        while(curr && curr->next) {
            if(newHead == NULL) {
                newHead = curr->next;
                tail = curr->next;
            }
            else {
                tail->next = curr->next;
                tail = curr->next;
            }

            curr->next = curr->next->next;
            curr = curr->next;
        }

        // Return the head of the clone linked list
        return newHead;
    }
};
