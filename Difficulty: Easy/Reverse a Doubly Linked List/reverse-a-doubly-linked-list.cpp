/*
class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        // code here
        if (!head->next) {
            return head;
        }
        
        Node* cur = head;
        Node* prevNode = nullptr;
        Node* nextNode;
        while (cur) {
            nextNode = cur->next;
            
            cur->prev = cur->next;
            cur->next = prevNode;
            
            prevNode = cur;
            cur = nextNode;
        }
        
        return prevNode;
    }
};