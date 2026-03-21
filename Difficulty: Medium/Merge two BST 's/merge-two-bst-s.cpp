/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void inorder(Node* root, vector<int> &v) {
        if(root == NULL) {
            return;
        }

        inorder(root->left, v);
        v.push_back(root->data);
        inorder(root->right, v);
    }
    
    vector<int> merge(vector<int> &a, vector<int> &b) {
        int i = 0, j = 0;
        vector<int> res;

        while(i < a.size() && j < b.size()) {
            if(a[i] < b[j]) {
                res.push_back(a[i++]);
            } else {
                res.push_back(b[j++]);
            }
        }

        while(i < a.size()) {
            res.push_back(a[i++]);
        }

        while(j < b.size()) {
            res.push_back(b[j++]);
        }

        return res;
    }

    vector<int> merge(Node *root1, Node *root2) {
        // code here
        vector<int> a, b;

        inorder(root1, a);
        inorder(root2, b);

        return merge(a, b);
    }
};