/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
public:
    struct Info {
        bool isBST;
        int size;
        int mn;
        int mx;
    };

    int ans = 0;
    Info dfs(Node* root) {
        if (!root) {
            return {true, 0, INT_MAX, INT_MIN};
        }

        Info L = dfs(root->left);
        Info R = dfs(root->right);

        Info cur;
        if (L.isBST && R.isBST && L.mx < root->data && R.mn > root->data) {
            cur.isBST = true;
            cur.size = L.size + R.size + 1;
            cur.mn = min(L.mn, root->data);
            cur.mx = max(R.mx, root->data);
            ans = max(ans, cur.size);
        } else {
            cur.isBST = false;
            //cur.size = 0;
            //cur.mn = INT_MIN;
            //cur.mx = INT_MAX;
        }

        return cur;
    }

    int largestBst(Node* root) {
        dfs(root);
        return ans;
    }
};