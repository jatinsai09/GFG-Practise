// User function Template for C++

/* Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};*/
class Solution {
  public:
    vector<int> inOrder(Node* root) {
        // code here
        vector<int> ans;
        Node* cur = root;

        while (cur != NULL) {
            if (cur->left == NULL) {
                ans.push_back(cur->data);
                cur = cur->right;
            } else {
                Node* pred = cur->left;
                while (pred->right != NULL && pred->right != cur) {
                    pred = pred->right;
                }

                if (pred->right == NULL) {
                    pred->right = cur;
                    cur = cur->left;
                } else {
                    ans.push_back(cur->data);
                    pred->right = NULL;
                    cur = cur->right;
                }
            }
        }

        return ans;
    }
};