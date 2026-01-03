/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/

class Solution {
  public:
    // Function to remove duplicates from sorted linked list.
    Node* removeDuplicates(Node* head) {
        Node* cur = head, *nxt;
        
        while (cur) {
            nxt = cur->next;
            while (nxt && nxt->data == cur->data) {
                nxt = nxt->next;
            } 
            cur->next = nxt;
            cur = cur->next;
        }
        // code here
        return head;
    }
};