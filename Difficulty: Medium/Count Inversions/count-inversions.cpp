class Solution {
  public:
  
    int merge(vector<int> &a,int low,int mid,int high){
        int left=low,right=mid+1,cnt=0;
        vector<int> temp;
        
        while(left<=mid && right<=high){
            if(a[left]<=a[right]){
                temp.push_back(a[left++]);
            } else {
                temp.push_back(a[right++]);
                cnt+=(mid-left+1);
            }
        }
        
        
        while(right<=high){
            temp.push_back(a[right++]);
        }
        while(left<=mid){
            temp.push_back(a[left++]);
        }
        
        for(int i=low;i<=high;i++){
            a[i]=temp[i-low];
        }
        
        return cnt;
    }
    
    int mergeSort(vector<int> &a,int low,int high){
        int cnt=0;
        if(low>=high){
            return cnt;
        }
        
        int mid=(low+high)>>1;
            
        cnt+=mergeSort(a,low,mid);
        cnt+=mergeSort(a,mid+1,high);
            
        cnt+=merge(a,low,mid,high);
        return cnt;
    }
    // Function to count inversions in the array.
    int inversionCount(vector<int> &arr) {
        int n=arr.size();
        
        return mergeSort(arr,0,n-1);
        // Your Code Here
    }
};
