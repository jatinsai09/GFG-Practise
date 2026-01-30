class Solution {
  public:
    void rearrangeQueue(queue<int> &q) {
        // code here
        int n = q.size();
    
        // If queue has less than 2 elements, nothing to do
        if (n <= 1) return;
        
        queue<int> firstHalf;
        
        // Move first half into auxiliary queue
        for (int i = 0; i < n / 2; i++) {
            firstHalf.push(q.front());
            q.pop();
        }
        
        // Interleave elements of firstHalf and remaining elements in q
        while (!firstHalf.empty()) {
            q.push(firstHalf.front());
            firstHalf.pop();
            
            q.push(q.front());
            q.pop();
        }
    }
};