class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        // code here
        int buy = prices[0], n = prices.size(), max_profit = 0;
        for(int i = 1; i < n; i++){
            int profit = prices[i] - buy;
            if(profit < 0){
                buy = prices[i];
            } else {
                max_profit = max(max_profit, profit);
            }
        }
        return max_profit;
    }
};
