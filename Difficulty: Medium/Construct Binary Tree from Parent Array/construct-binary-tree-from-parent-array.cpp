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
    Node* createTree(vector<int>& parent) {
        // code here
        int n = parent.size();
        
        vector<Node*> v(n, nullptr);
        for(int i = 0; i < n; i++) {
            v[i] = new Node(i);
        }
    
        Node* root = nullptr;
    
        for(int i = 0; i < n; i++) {
            if(parent[i] == -1) {
                root = v[i];
            } else {
                Node* p = v[parent[i]];
                if(p->left == nullptr) {
                    p->left = v[i];
                } else {
                    p->right = v[i];
                }
            }
        }
        return root;
    }
};
