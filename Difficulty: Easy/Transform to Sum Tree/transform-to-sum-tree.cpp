/* Structure for Tree Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    int f(Node *root) {
        if (!root) {
            return 0;
        }
        
        int ls = 0, rs = 0;
        if (root->left) {
            ls = root->left->data + f(root->left);
        }
        if (root->right) {
            rs = root->right->data + f(root->right);
        }
        
        return root->data = ls + rs;
    }
    void toSumTree(Node *root) {
        // code here
        f(root);
    }
};