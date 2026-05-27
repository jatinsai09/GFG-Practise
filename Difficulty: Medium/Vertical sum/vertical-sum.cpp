/* Structure of binary tree node
class Node{
public:
    int data;
    Node* left, right;
    Node(int item)
    {
        data = item;
        left = nullptr;
        right = nullptr;
    }
}
*/
class Solution {
  public:
    vector<int> verticalSum(Node* root) {
        // code here
        map<int, int> mp;
        
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            Node* cur = it.first;
            int col = it.second;
            
            mp[col] += cur->data;
            
            if (cur->left) {
                q.push({cur->left, col - 1});
            }
            if (cur->right) {
                q.push({cur->right, col + 1});
            }
        }
        
        vector<int> res;
        for (auto &p: mp) {
            res.push_back(p.second);
        }
        return res;
    }
};