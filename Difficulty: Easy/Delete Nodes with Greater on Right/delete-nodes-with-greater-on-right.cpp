/* Structure of a Linked List node
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node *compute(Node *head) {
        // code here
        if (!head->next) {
            return head;
        }
        
        Node* prev = NULL;
        Node* cur = head;
        Node* nxt;
        
        while (cur) {
            nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        
        Node* rhead = prev;
        cur = rhead->next;
        
        while (cur) {
            if (cur->data < prev->data) {
                prev->next = cur->next;
            } else {
                prev = cur;
            }
            cur = cur->next;
        }
        
        prev = NULL;
        cur = rhead;
        
        while (cur) {
            nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        return prev;
    }
};