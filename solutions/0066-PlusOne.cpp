class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i = digits.size() - 1; i >= 0; --i) {
            digits[i] = (digits[i] + 1) % 10;
            if(digits[i]) break;
        }
        if(!digits[0]) digits.insert(digits.begin(), 1);
        return digits;
    }
};
