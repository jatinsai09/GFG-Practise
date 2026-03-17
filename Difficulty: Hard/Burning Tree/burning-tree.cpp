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
  
    Node* mark(Node* root, int target, unordered_map<Node*, Node*>& par) {
        queue<Node*> q;
        q.push(root);
        Node* res = NULL;
        
        while(!q.empty()){
            Node* cur = q.front();
            q.pop();
            
            if(cur->data == target) res = cur;
            
            if(cur->left){
                par[cur->left] = cur;
                q.push(cur->left);
            }
            
            if(cur->right){
                par[cur->right] = cur;
                q.push(cur->right);
            }
        }
        
        return res;
    }
  
    int minTime(Node* root, int target) {
        
        unordered_map<Node*, Node*> par;
        Node* start = mark(root, target, par);
        
        queue<Node*> q;
        unordered_map<Node*, bool> vis;
        
        q.push(start);
        vis[start] = true;
        
        int time = 0;
        
        while(!q.empty()){
            int sz = q.size();
            bool burn = false;
            
            while(sz--){
                Node* cur = q.front();
                q.pop();
                
                if(cur->left && !vis[cur->left]){
                    burn = true;
                    vis[cur->left] = true;
                    q.push(cur->left);
                }
                
                if(cur->right && !vis[cur->right]){
                    burn = true;
                    vis[cur->right] = true;
                    q.push(cur->right);
                }
                
                if(par[cur] && !vis[par[cur]]){
                    burn = true;
                    vis[par[cur]] = true;
                    q.push(par[cur]);
                }
            }
            
            if(burn) time++;
        }
        
        return time;
    }
};