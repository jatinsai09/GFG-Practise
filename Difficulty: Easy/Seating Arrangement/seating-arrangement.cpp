class Solution {
  public:
    bool canSeatAllPeople(int k, vector<int> &seats) {
        // code here
        int n = seats.size();
        
        for (int i = 1; i < n; i++) {
            if (seats[i] + seats[i - 1] == 2) {
                return false;
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (seats[i]) {
                i++;
                continue;
            }
            
            if (i + 1 == n || seats[i + 1] != 1) {
                k--;
                i++;
            }
        }
        
        return k <= 0;
    }
};