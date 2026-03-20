/* BST Node
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        Node* pre = NULL;
        Node* suc = NULL;
        
        Node* cur = root;
        
        while(cur) {
            if((cur->data) < key) {
                pre = cur;
                cur = cur->right;
            }
            else if((cur->data) > key) {
                suc = cur;
                cur = cur->left;
            }
            else
            {
                Node* t = cur->left;
                while(t) {
                    pre = t;
                    t = t->right;
                }
                
                t = cur->right;
                while(t) {
                    suc = t;
                    t = t->left;
                }
                break;
            }
        }
        
        return {pre, suc};
    }
};