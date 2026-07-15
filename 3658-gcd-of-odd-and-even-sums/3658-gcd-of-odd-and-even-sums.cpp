class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumOdd = 0;
        int sumEven = 0;

        int tillNum = 2 * n;

        for(int i=1; i<tillNum; i++){
            if(i % 2 == 1) sumOdd += i;
            else sumEven += i;
        }

        return __gcd(sumOdd, sumEven);
    }
};