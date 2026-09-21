/* Structure of binary tree Node
class Node {
    public:
    int data;
    Node *left, *right;
    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    bool areAnagrams(Node* root1, Node* root2) {
        // code here
        queue<Node*> q1, q2;
        q1.push(root1);
        q2.push(root2);
        
        while (!q1.empty() && !q2.empty()) {
            int s1 = q1.size(), s2 = q2.size();
            
            if (s1 != s2) {
                return false;
            }
            
            vector<int> a, b;
            while (s1--) {
                {
                    Node* n1 = q1.front();
                    q1.pop();
                    
                    a.push_back(n1->data);
                    
                    if (n1->left) {
                        q1.push(n1->left);
                    }
                    if (n1->right) {
                        q1.push(n1->right);
                    }
                }
                
                {
                    Node* n2 = q2.front();
                    q2.pop();
                    
                    b.push_back(n2->data);
                    
                    if (n2->left) {
                        q2.push(n2->left);
                    }
                    if (n2->right) {
                        q2.push(n2->right);
                    }
                }
            }
            
            sort(begin(a), end(a));
            sort(begin(b), end(b));
            
            if (a != b) {
                return false;
            }
        }
        
        return q1.empty() && q2.empty();
    }
};
