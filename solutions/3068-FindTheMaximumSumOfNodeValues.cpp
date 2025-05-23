class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long result = 0;
        for(int& n : nums) {
            result += n;
            n = ((n | k) & (~n | ~k)) - n;
        }
        sort(nums.begin(), nums.end(), greater<int>());
        for(int i = 0; i < nums.size() - 1; i += 2) {
            if(nums[i] + nums[i+1] > 0) result += nums[i] + nums[i+1];
            else break;
        }
        return result;
    }
};
