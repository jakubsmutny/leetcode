class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int diff = 0;
        for(int i = 0; i < nums.size(); i++)
            diff = max(diff, abs(nums[(i+1) % nums.size()] - nums[i]));
        return diff;
    }
};
