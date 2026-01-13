/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution {
  public:
    bool same(Node* a, Node* b) {
        if (a == NULL && b == NULL) {
            return true;
        }
        
        if (a == NULL || b == NULL) {
            return false;
        }
        
        if (a->data != b->data) {
            return false;
        }
        
        return (same(a->left, b->left) && same(a->right, b->right));
    }
    
    // Function to check if S is a subtree of tree T.
    bool isSubTree(Node* T, Node* S) {
        // Your code here
        if (S == NULL) {
            return 1;
        }
        if (T == NULL) {
            return 0;
        }
        
        if (same(T, S)) {
            return 1;
        }
        
        return (isSubTree(T->left, S) || isSubTree(T->right, S));
    }
};