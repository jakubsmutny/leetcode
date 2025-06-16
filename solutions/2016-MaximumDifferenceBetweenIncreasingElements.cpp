class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int minimum = INT_MAX;
        int result = 0;
        for(const int& n : nums) {
            minimum = min(n, minimum);
            result = max(n - minimum, result);
        }
        return result ? result : -1;
    }
};
