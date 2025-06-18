class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for(int i = 0; i < nums.size(); i++) {
            if(i % 3 == 0) result.push_back(vector<int>());
            result.back().push_back(nums[i]);
        }
        for(const vector<int>& v : result)
            if(v[2] - v[0] > k) return vector<vector<int>>();
        return result;
    }
};
