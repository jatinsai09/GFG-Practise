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
}; */

class Solution {
  public:
    bool find(Node* root, int target, vector<char>& path) {
        if (!root) {
            return false;
        }
        if (root->data == target) {
            return true;
        }
        
        path.push_back('L');
        if (find(root->left, target, path)) {
            return true;
        }
        path.pop_back();
        
        path.push_back('R');
        if (find(root->right, target, path)) {
            return true;
        }
        path.pop_back();
        
        return false;
    }
    int numberOfTurns(Node* root, int p, int q) {
        // code here
        vector<char> pathP, pathQ;
        
        find(root, p, pathP);
        find(root, q, pathQ);
        
        int i = 0, n = pathP.size(), m = pathQ.size();
        while (i < n && i < m) {
            if (pathP[i] != pathQ[i]) {
                break;
            }
            i++;
        }
        
        vector<char> path;
        for (int j = n - 1; j >= i; j--) {
            path.push_back(pathP[j]);
        }
        for (int j = i; j < m; j++) {
            path.push_back(pathQ[j]);
        }
        
        int sz = path.size(), turns = 0;
        for (int i = 1; i < sz; i++) {
            turns += (path[i] != path[i - 1]);
        }
        
        return (turns ? turns : -1);
    }
};