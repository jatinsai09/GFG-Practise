/*
class NodeLL {
  public:
    int data;
    NodeLL *next;

    NodeLL(int x) {
        data = x;
        next = NULL;
    }
};
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    Node *linkedListToBinaryTree(NodeLL *head) {
        // code here
        if (head == NULL) {
            return NULL;
        }

        Node* root = new Node(head->data);
        queue<Node*> q;
        q.push(root);
        head = head->next;

        while (head) {
            Node* cur = q.front();
            q.pop();
            
            {
                Node* left = new Node(head->data);
                cur->left = left;
                
                q.push(left);
                head = head->next;
            }

            if (head) {
                Node* right = new Node(head->data);
                cur->right = right;
                
                q.push(right);
                head = head->next;
            }
        }

        return root;
    }
};