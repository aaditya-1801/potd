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
        memset(t, -1, sizeof(t));
        return solve(nums, 0, 0, 0);
    }
};