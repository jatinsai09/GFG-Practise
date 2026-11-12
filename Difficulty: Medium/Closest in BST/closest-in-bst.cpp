/* Structure of a Binary Search Tree node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    int minDiff(Node *root, int k) {
        // code here
        int res = abs(k - root->data);
        
        Node* temp = root;
        while (temp) {
            res = min(res, abs(k - temp->data));
            
            if (temp->data == k) {
                return 0;
            }
            
            if (k < temp->data) {
                temp = temp->left;
            } else {
                temp = temp->right;
            }
        }
        
        return res;
    }
};
