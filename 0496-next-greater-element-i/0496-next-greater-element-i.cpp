class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        int n = nums1.size();
        int m = nums2.size();

        for (int i = 0; i < n; i++) {
            int num = nums1[i];
            int idx = -1;

            for (int j = 0; j < m; j++) {
                if (nums2[j] == num) {
                    idx = j;
                    break;
                }
            }
            idx++;

            while (idx < m && nums2[idx] <= num) idx++;

            if (idx == m) res.push_back(-1);
            else res.push_back(nums2[idx]);
        }

        return res;
    }
};