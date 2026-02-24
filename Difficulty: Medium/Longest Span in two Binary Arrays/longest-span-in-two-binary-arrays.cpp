class Solution {
  public:
    int equalSumSpan(vector<int> &a1, vector<int> &a2) {
        // code here
        int n = a1.size();
        unordered_map<int, int> mp;
        
        int prefixSum = 0, maxLen = 0;
        
        mp[0] = -1;
        for(int i = 0; i < n; i++) {
            prefixSum += (a1[i] - a2[i]);
            
            if(mp.find(prefixSum) != mp.end()) {
                maxLen = max(maxLen, i - mp[prefixSum]);
            } else {
                mp[prefixSum] = i;
            }
        }
        
        return maxLen;
    }
};