class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> diff = vector<int>(nums.size() + 1, 0);
        int diffAt = 0;
        int l = -1;
        int r = queries.size() + 1;
        while(r - l > 1) {
            int n = (l + r) / 2;
            updateDiff(diff, queries, diffAt, n);
            if(validDiff(nums, diff)) r = diffAt = n;
            else l = diffAt = n;
        }
        return r > queries.size() ? -1 : r;
    }

private:
    bool validDiff(const vector<int>& nums, const vector<int>& diff) {
        int accepted = 0;
        for(int i = 0; i < nums.size(); ++i) {
            accepted += diff[i];
            if(nums[i] > accepted)
                return false;
        }
        return true;
    }

    void updateDiff(vector<int>& diff, const vector<vector<int>>& queries, int from, int to) {
        if(from == to) return;
        for(int i = min(from, to); i < max(from, to); ++i) {
            diff[queries[i][0]] += queries[i][2] * (from > to ? -1 : 1);
            diff[queries[i][1] + 1] -= queries[i][2] * (from > to ? -1 : 1);
        }
    }
};
