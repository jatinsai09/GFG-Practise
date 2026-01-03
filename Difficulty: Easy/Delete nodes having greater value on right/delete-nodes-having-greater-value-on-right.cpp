/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
    Node *reverse(Node *head) {
        Node *prev = nullptr, *cur = head;
        
        while (cur) {
            Node* nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        return prev;
    }
    Node *compute(Node *head) {
        // your code goes here
        int mx = 0;
        head = reverse(head);
        Node *prev = nullptr, *cur = head;
        
        while (cur) {
            if (cur->data >= mx) {
                mx = cur->data;
                prev = cur;
                cur = cur->next;
            } else {
                prev->next = cur->next;
                cur = cur->next;
            }
        }
        
        return reverse(head);
    }
};