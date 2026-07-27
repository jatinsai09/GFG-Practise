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
    Node *constructBinaryTree(vector<int> &pre, vector<int> &preMirror) {
        // code here
        int n = pre.size();
        unordered_map<int, int> mp;
        
        for (int i = 0; i < n; i++) {
            mp[preMirror[i]] = i;
        }
        
        int pi = 0;
        function<Node*(int, int)> f = [&](int st, int en) -> Node* {
            if (st > en) {
                return NULL;
            }
            
            Node *root = new Node(pre[pi++]);
            
            if (st == en || pi >= n) {
                return root;
            }
            
            int ind = mp[pre[pi]];
            int l = n - ind, r = ind - st - 1;
            
            root->left = f(ind, en);
            root->right = f(st + 1, ind - 1);
            
            return root;
        };
        
        
        return f(0, n - 1);
    }
};