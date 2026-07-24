/* Structure of Binary Tree Node
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
    int longestConsecutive(Node* root) {
        // code here
        int res = 1;
        
        function<void(Node*, int, int)> dfs = [&](Node* root, int prev, int cur) -> void {
            if (!root) {
                return;
            }
            
            if (root->data == prev + 1) {
                cur++;
            } else {
                cur = 1;
            }
            
            res = max(res, cur);
            
            dfs(root->left, root->data, cur);
            dfs(root->right, root->data, cur);
        };
        
        dfs(root, root->data - 1, 0);
        return (res == 1 ? -1 : res);
    }
};