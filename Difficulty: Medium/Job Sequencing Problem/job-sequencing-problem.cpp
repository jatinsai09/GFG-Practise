
class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        int n=deadline.size();
        vector<pair<int,int>> jobs;
        vector<int> res(2,0);
        
        for(int i=0;i<n;i++){
            jobs.push_back({deadline[i],profit[i]});
        }
        
        sort(begin(jobs),end(jobs));
        priority_queue<int,vector<int>,greater<int>> pq;
        for(const auto &job : jobs){
            if(job.first>pq.size()){
                pq.push(job.second);
            }
            else if(!pq.empty() && job.second > pq.top()){
                pq.pop();
                pq.push(job.second);
            }
        }
        
        while(!pq.empty()){
            res[0]++;
            res[1]+=pq.top();
            pq.pop();
        }
        return res;
    }
};

