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
    int countAllPaths(Node *root, int k) {
        // code here
        unordered_map<int,int> pre;
        pre[0] = 1;
        
        auto countPaths=[&](auto &&self, Node* node, int cur){
            if(!node){
                return 0;
            }
            
            int c = 0;
            cur += node->data;
            c+=pre[cur - k];
            
            pre[cur]++;
            
            c += self(self, node->left, cur);
            c += self(self, node->right, cur);
            
            pre[cur]--;
            
            return c;
        };
        
        return countPaths(countPaths, root, 0);
    }
};