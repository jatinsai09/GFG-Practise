/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    vector<int> preOrder(Node* root) {
        // code here
        vector<int> ans;
        if (root == NULL) {
            return ans;
        }

        stack<Node*> st;
        st.push(root);

        while (!st.empty()) {
            Node* cur = st.top();
            st.pop();

            ans.push_back(cur->data);

            if (cur->right != NULL) {
                st.push(cur->right);
            }
            if (cur->left != NULL) {
                st.push(cur->left);
            }
        }

        return ans;
    }
};