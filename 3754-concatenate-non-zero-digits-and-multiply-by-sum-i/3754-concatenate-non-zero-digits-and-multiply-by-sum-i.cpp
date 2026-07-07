class Solution {
public:
    long long sum (int x){
        long long sum = 0;
        while(x){
            int ld = x % 10;
            sum += ld;
            x /= 10;
        }
        return sum;
    }

    long long sumAndMultiply(int n) {
        string s = to_string(n);
        int sz = s.length();

        string newInt = "" ;
        for(int i=0; i<sz; i++){
            if(s[i] != '0') newInt += s[i];
        }

        long long res = newInt.empty() ? 0 : stoll(newInt);

        return sum(n) * res;
    }
};