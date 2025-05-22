class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> count = vector<int>(3, 0);
        for(const int& num : nums)
            ++count[num];
        for(int i = 0; i < nums.size(); ++i) {
            if(i < count[0]) nums[i] = 0;
            if(i >= count[0] && i < count[0] + count[1]) nums[i] = 1;
            if(i >= count[0] + count[1]) nums[i] = 2;
        }
    }
};
