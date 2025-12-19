/*
class Node {
public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    int cycleStart(Node* head) {
        // code here
        Node *slow = head, *fast = head;
        
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                break;
            }
        }
        
        if (slow != fast) {
            return -1;
        }
        
        fast = head;
        while (slow != fast) {
            fast = fast->next;
            slow = slow->next;
        }
        
        return slow->data;
    }
};