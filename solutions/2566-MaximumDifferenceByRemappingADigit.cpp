class Solution {
public:
    int minMaxDifference(int num) {
        vector<int> digits;
        while(num) {
            digits.push_back(num % 10);
            num /= 10;
        }
        reverse(digits.begin(), digits.end());
        int maxPos = 0;
        while(maxPos < digits.size() - 1 && digits[maxPos] == 9) maxPos++;
        int maxDigit = digits[maxPos];
        int minDigit = digits[0];
        int max = 0;
        int min = 0;
        for(const int& d : digits) {
            max *= 10;
            min *= 10;
            max += (d == maxDigit ? 9 : d);
            min += (d == minDigit ? 0 : d);
        }
        return max - min;
    }
};
