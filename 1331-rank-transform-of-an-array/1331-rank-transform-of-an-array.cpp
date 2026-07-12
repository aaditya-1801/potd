class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp = arr;
        sort(temp.begin(), temp.end());

        int r = 1;
        unordered_map<int, int> mp;
        for(int num : temp){
            if(!mp.count(num))
                mp[num] = r++;
        }

        for(int &x : arr){
            x = mp[x];
        }

        return arr;
    }
};