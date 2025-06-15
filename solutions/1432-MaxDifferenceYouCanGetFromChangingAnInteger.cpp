class Solution {
public:
    int maxDiff(int num) {
        vector<int> digits;
        while(num) {
            digits.push_back(num % 10);
            num /= 10;
        }
        reverse(digits.begin(), digits.end());
        int maxPos = 0;
        int minPos = 0;
        while(maxPos < digits.size() - 1 && digits[maxPos] == 9) maxPos++;
        while(minPos < digits.size() - 1 && digits[minPos] <= 1) minPos++;
        int maxDigit = digits[maxPos];
        int minDigit = digits[minPos];
        int max = 0;
        int min = 0;
        for(const int& d : digits) {
            max *= 10;
            min *= 10;
            max += (d == maxDigit ? 9 : d);
            min += (d == minDigit ? (digits[0] == minDigit ? 1 : 0) : d);
        }
        return max - min;
    }
};
