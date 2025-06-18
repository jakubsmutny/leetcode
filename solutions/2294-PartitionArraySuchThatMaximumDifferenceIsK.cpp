class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int result = 0;
        int minimum = (-1) * k - 1;
        for(int i = 0; i < nums.size(); i++)
            if(nums[i] - minimum > k) {
                minimum = nums[i];
                result++;
            }
        return result;
    }
};
