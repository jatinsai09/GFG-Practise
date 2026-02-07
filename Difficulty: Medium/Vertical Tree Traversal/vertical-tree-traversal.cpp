/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    vector<vector<int>> verticalOrder(Node *root) {
        // code here
        map<int, vector<int>> mp;
        queue<pair<Node*, int>> q;
    
        q.push({root, 0});
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
    
            Node* cur = it.first;
            int hd = it.second;
    
            mp[hd].push_back(cur->data);
    
            if (cur->left) {
                q.push({cur->left, hd - 1});
            }
            if (cur->right) {
                q.push({cur->right, hd + 1});
            }
        }

        vector<vector<int>> res;
        for (auto &x : mp) {
            res.push_back(x.second);
        }
    
        return res;
    }
};