class Solution {
public:
    const int MOD = 1e9 + 7;
    int t[201][201][201];

    int solve(vector<int>& nums, int i, int gcd1, int gcd2){
        if(i == nums.size()){
            bool bothNonEmpty = (gcd1 != 0 && gcd2 != 0);
            bool gcdMatched = (gcd1 == gcd2);

            return bothNonEmpty && gcdMatched ? 1 : 0 ;
        }

        if(t[i][gcd1][gcd2] != -1) return t[i][gcd1][gcd2];

        int skip = solve(nums, i+1, gcd1, gcd2);
        int take1 = solve(nums, i+1, __gcd(gcd1, nums[i]), gcd2);
        int take2 = solve(nums, i+1, gcd1, __gcd(gcd2, nums[i]));

        return t[i][gcd1][gcd2] = (0LL + skip + take1 + take2) % MOD;  // integer overflow
    }

    int subsequencePairCount(vector<int>& nums) {
        // memset(t, -1, sizeof(t));
        // return solve(nums, 0, 0, 0);

        int n = nums.size();
        int maxEl = *max_element(nums.begin(), nums.end());

        // int t[n+1][maxEl+1][maxEl+1];
        vector<vector<int>> prev(maxEl+1, vector<int>(maxEl+1, 0));

        for(int gcd1 = 0; gcd1 <= maxEl; gcd1++){
            for(int gcd2 = 0; gcd2 <= maxEl; gcd2++){

                bool bothNonEmpty = (gcd1 != 0 && gcd2 != 0);
                bool gcdMatched = (gcd1 == gcd2);

                prev[gcd1][gcd2] = (bothNonEmpty && gcdMatched) ? 1 : 0;
            }
        }

        for(int i = n-1; i>=0; i--){
            vector<vector<int>> curr(maxEl+1, vector<int>(maxEl+1, 0));
            for(int gcd1 = maxEl; gcd1 >=0; gcd1--){
                for(int gcd2 = maxEl; gcd2 >=0; gcd2--){
                    // int skip = t[i+1][gcd1][gcd2];
                    // int take1 = t[i+1][__gcd(gcd1, nums[i])][gcd2];
                    // int take2 = t[i+1][gcd1][__gcd(gcd2, nums[i])];
                    int skip = prev[gcd1][gcd2];
                    int take1 = prev[__gcd(gcd1, nums[i])][gcd2];
                    int take2 = prev[gcd1][__gcd(gcd2, nums[i])];

                    curr[gcd1][gcd2] = (0LL + skip + take1 + take2) % MOD;
                }
            }
            prev = move(curr);
        }
        return prev[0][0];
    }
};