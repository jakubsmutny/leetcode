class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> diff = vector<int>(nums.size() + 1, 0);
        for(const auto& pair : queries) {
            ++diff[pair[0]];
            --diff[pair[1] + 1];
        }
        int maxAcceptedValue = 0;
        for(int i = 0; i < nums.size(); ++i) {
            maxAcceptedValue += diff[i];
            if(nums[i] > maxAcceptedValue)
                return false;
        }
        return true;
    }
};
