class Solution {
#define ll long long int 
  private:
    vector<ll> tree;
    ll lcm(ll a, ll b) {
        return (a / __gcd(a, b)) * b;
    }
    void buildTree(vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }
        
        int mid = start + (end - start) / 2;
        int leftChild = 2 * node + 1;
        int rightChild = 2 * node + 2;
        
        buildTree(arr, leftChild, start, mid);
        buildTree(arr, rightChild, mid + 1, end);
        
        tree[node] = lcm(tree[leftChild], tree[rightChild]);
    }
    
    void updateTree(int node, int start, int end, int ind, int val) {
        if (start == end) {
            tree[node] = val;
            return;
        }
        
        int mid = start + (end - start) / 2;
        int leftChild = 2 * node + 1;
        int rightChild = 2 * node + 2;

        if (ind <= mid) {
            updateTree(leftChild, start, mid, ind, val);
        } else {
            updateTree(rightChild, mid + 1, end, ind, val);
        }

        tree[node] = lcm(tree[leftChild], tree[rightChild]);
    }
    
    ll queryTree(int node, int start, int end, int left, int right) {
        if (right < start || left > end) {
            return 1;
        }
        
        if (left <= start && right >= end) {
            return tree[node];
        }
        
        int mid = start + (end - start) / 2;
        int leftChild = 2 * node + 1;
        int rightChild = 2 * node + 2;

        ll leftLCM = queryTree(leftChild, start, mid, left, right);
        ll rightLCM = queryTree(rightChild, mid + 1, end, left, right);

        return lcm(leftLCM, rightLCM);
    }
  public:
    vector<long long> RangeLCMQuery(vector<int> &arr, vector<vector<int>> &queries) {
        // code here
        int n = arr.size();
        tree.resize(n * 4);
        vector<ll> res;
        
        buildTree(arr, 0, 0, n - 1);
        
        for (auto &q: queries) {
            if (q[0] == 1) {
                int ind = q[1], val = q[2];
                
                arr[ind] = val;
                
                updateTree(0, 0, n - 1, ind, val);
            } else {
                int l = q[1], r = q[2];
                
                res.push_back(queryTree(0, 0, n - 1, l, r));
                
            }
        }
        
        return res;
    }
};