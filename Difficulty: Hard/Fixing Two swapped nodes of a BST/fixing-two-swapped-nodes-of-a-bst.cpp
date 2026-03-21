// User function Template for C++

/*struct Node
{
    int data;
    struct Node *left, *right;
};*/

class Solution {
  public:
    Node* first = NULL;
    Node* middle = NULL;
    Node* last = NULL;
    Node* prev = NULL;

    void inorder(Node* root) {
        if(root == NULL) {
            return;
        }

        inorder(root->left);

        if(prev != NULL && prev->data > root->data) {
            if(first == NULL) {
                first = prev;
                middle = root;
            } else {
                last = root;
            }
        }
        prev = root;

        inorder(root->right);
    }

    struct Node *correctBST(struct Node *root) {
        // code here
        inorder(root);

        if(first != NULL && last != NULL) {
            swap(first->data, last->data);
        }
        else if(first != NULL && middle != NULL) {
            swap(first->data, middle->data);
        }

        return root;
    }
};