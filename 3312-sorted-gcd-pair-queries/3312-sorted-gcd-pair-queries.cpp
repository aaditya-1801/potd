class Solution {
public:
    // O(n + M log M + q log M)
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());

        vector<int> freq(mx + 1);
        for (int x : nums) freq[x]++;

        vector<long long> gcdCnt(mx + 1);

        // Count pairs divisible by i
        for (int i = mx; i >= 1; i--) {
            long long cnt = 0;

            for (int j = i; j <= mx; j += i)
                cnt += freq[j];

            gcdCnt[i] = cnt * (cnt - 1) / 2;

            // Remove pairs whose gcd is a multiple of i
            for (int j = 2 * i; j <= mx; j += i)
                gcdCnt[i] -= gcdCnt[j];
        }

        vector<long long> pref;
        vector<int> values;

        for (int i = 1; i <= mx; i++) {
            if (gcdCnt[i] > 0) {
                values.push_back(i);
                if (pref.empty())
                    pref.push_back(gcdCnt[i]);
                else
                    pref.push_back(pref.back() + gcdCnt[i]);
            }
        }

        vector<int> ans;

        for (long long q : queries) {
            int idx = lower_bound(pref.begin(), pref.end(), q + 1) - pref.begin();
            ans.push_back(values[idx]);
        }

        return ans;
    }
};

// class Solution {
// public:
        // O(n² log n)
//     vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
//         int n = nums.size();

//         vector<int> gcdPairs;
//         int k = 0;
//         for(int i=0; i<n; i++){
//             for(int j=i+1; j<n; j++)
//                 gcdPairs.push_back(__gcd(nums[i], nums[j]));
//         }

//         sort(gcdPairs.begin(), gcdPairs.end());

//         vector<int> ans;
//         for(int i=0; i<queries.size(); i++){
//             ans.push_back(gcdPairs[queries[i]]);
//         }

//         return ans;
//     }
// };