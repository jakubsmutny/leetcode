class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int valid = 0;
        for(int i = 0; i < nums.size() - 1; i++)
            valid = max(valid, abs(nums[i] - nums[i+1]));
        int invalid = -1;
        while(valid > invalid + 1) {
            int n = (valid + invalid) / 2;
            if(pairsWithDiff(n, nums) >= p) valid = n;
            else invalid = n;
        }
        return valid;
    }

private:
    int pairsWithDiff(int diff, const vector<int>& nums) {
        int count = 0;
        for(int i = 0; i < nums.size() - 1; i++)
            if(abs(nums[i] - nums[i+1]) <= diff) {
                count++;
                i++;
            }
        return count;
    }
};
