/*
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* intersectPoint(Node* head1, Node* head2) {
        //  Code Here
        Node *x = head1, *y = head2;
        
        while (1) {
            if (x == nullptr) {
                x = head2;
            }
            if (y == nullptr) {
                y = head1;
            }
            
            if (x == y) {
                return x;
            }
            x = x->next;
            y = y->next;
        }
    }
};