class Solution {
  public:
    void mergeArrays(vector<int>& nums1, vector<int>& nums2) {
        // code here
        int m = nums1.size(), n = nums2.size(); 
        int t = m + n, gap = (t + 1) / 2;

        while (gap) {
            int i = 0, j = gap;

            while (j < t) {
                if (j < m && nums1[i] > nums1[j]) {
                    swap(nums1[i], nums1[j]);
                } else if (i < m && j >= m && nums1[i] > nums2[j - m]) {
                    swap(nums1[i], nums2[j - m]);
                } else if (i >= m && nums2[i - m] > nums2[j - m]) {
                    swap(nums2[i - m], nums2[j - m]);
                }
                i++;
                j++;
            }

            if (gap == 1) {
                break;
            }
            gap = (gap + 1) / 2;
        }
    }
};