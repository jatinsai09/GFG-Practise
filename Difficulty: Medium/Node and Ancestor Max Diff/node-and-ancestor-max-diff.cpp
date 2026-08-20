/* Structure of Binary Tree Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
  
    int dfs(Node* root, int maxAncestor) {
        if (!root) {
            return INT_MIN;
        }
        
        int diff = maxAncestor - root->data;
        
        maxAncestor = max(root->data, maxAncestor);
        
        int l = dfs(root->left, maxAncestor);
        int r = dfs(root->right, maxAncestor);
        
        return max({diff, l, r});
    }
    int maxDiff(Node* root) {
        // code here
        return dfs(root, -1e6);
    }
};