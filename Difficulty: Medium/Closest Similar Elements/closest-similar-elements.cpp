
class Solution {
    #define ll long long 
  public:
    bool closestSimilarElements(int n, vector<int> &arr, int indexDifference,
                                int valueDifference) {
        // code here
        multiset<ll> st;
        
        for (int j = 0; j < n; j++) {
            if (j > indexDifference) {
                st.erase(st.find(arr[j - indexDifference - 1]));
            }
            
            auto it = st.lower_bound(arr[j] - valueDifference);
            if (it != st.end() && llabs(*it - arr[j]) <= valueDifference) {
                return true;
            }
            
            st.insert(arr[j]);
        }
        
        return false;
    }
};
