// User function Template for C++

/* Linked List node structure

struct Node {
    int data;
    struct Node *next;
};

*/

class Solution {
  public:
    Node* removeAllDuplicates(struct Node* head) {
        // code here
        Node *dummy = new Node(-1);
        dummy->next = head;
        
        Node *prev = dummy, *cur = head;
        
        while (cur) {
            bool dup = false;
            while (cur->next && cur->data == cur->next->data) {
                dup = true;
                cur = cur->next;
            }
            
            if (dup) {
                prev->next = cur->next;
            } else {
                prev = prev->next;
            }
            cur = cur->next;
        }
        
        return dummy->next;
    }
};