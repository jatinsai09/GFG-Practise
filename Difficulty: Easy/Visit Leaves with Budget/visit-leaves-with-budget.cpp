/* Binary Tree Node Structure
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    int getCount(Node *root, int k) {
        // code here
        vector<int> costs;
        
        function<void(Node*, int)> dfs = [&](Node* root, int depth) -> void {
            if (!root) {
                return;
            }
            
            if (!root->left && !root->right) {
                costs.push_back(depth);
            }
            
            dfs(root->left, depth + 1);
            dfs(root->right, depth + 1);
        };
        dfs(root, 1);
        
        sort(begin(costs), end(costs));
        
        int res = 0;
        for (const auto &c: costs) {
            if (c > k) {
                break;
            }
            res++;
            k -= c;
        }
        
        return res;
    }
};