class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> result;
        int nearKeys = 0;
        for(int i = 0; i < k; i++) if(nums[i] == key) nearKeys++;
        for(int i = 0; i < nums.size(); i++) {
            if(i + k < nums.size() && nums[i+k] == key) nearKeys++;
            if(nearKeys) result.push_back(i);
            if(i - k >= 0 && nums[i-k] == key) nearKeys--;
        }
        return result;
    }
};
