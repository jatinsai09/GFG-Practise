/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    int ans = 0;
    
    int dfs(Node* root) {
        if (root == NULL) {
            return 0;
        }
        
        int l = dfs(root->left);
        int r = dfs(root->right);
        
        ans += abs(l) + abs(r);
        
        return root->data + l + r - 1;
    }
    
    int distCandy(Node* root) {
        // code here
        ans = 0;
        dfs(root);
        return ans;
    }
};