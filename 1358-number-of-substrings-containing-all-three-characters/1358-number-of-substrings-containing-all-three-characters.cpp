class Solution {
public:
    int numberOfSubstrings(string s) {
        int lastSeen[] = {-1,-1,-1};
        int cnt = 0;
        int n = s.size();

        for(int i=0; i<n; i++){
            lastSeen[s[i]-'a'] = i;
            int minEle = min(lastSeen[0], min(lastSeen[1], lastSeen[2]));
            cnt += minEle + 1;
        }
        return cnt;
    }
};