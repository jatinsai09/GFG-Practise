/* Binary Tree Node Structure
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; 
*/

class Solution {
  public:
    int absDiff(Node *root) {
        // code here
        int res = INT_MAX, prev = -1;
        
        function<void(Node*)> inorder = [&](Node* root) -> void {
            if (!root) {
                return;
            }
            
            inorder(root->left);
            if (prev != -1) {
                res = min(res, root->data - prev);
            }
            prev = root->data;
            inorder(root->right);
        };
        inorder(root);
        
        return res;
    }
};