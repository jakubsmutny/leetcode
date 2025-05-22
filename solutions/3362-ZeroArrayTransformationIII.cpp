using Query = vector<int>;

struct {
    bool operator()(const Query& a, const Query& b) {
        return a[0] < b[0];
    }
} CompareQueryLefter;

struct CompareQueryRighter {
    bool operator()(const Query& a, const Query& b) {
        return a[1] < b[1];
    }
};

class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        sort(queries.begin(), queries.end(), CompareQueryLefter);
        priority_queue<Query, vector<Query>, CompareQueryRighter> queryQueue;
        int toOpen = 0;
        int acceptedValue = 0;
        vector<int> queryEnds = vector<int>(nums.size(), 0);
        for(int i = 0; i < nums.size(); ++i) {
            while(toOpen < queries.size() && i >= queries[toOpen][0])
                queryQueue.push(queries[toOpen++]);
            while(acceptedValue < nums[i]) {
                if(queryQueue.empty()) return -1;
                if(queryQueue.top()[1] >= i) {
                    ++acceptedValue;
                    ++queryEnds[queryQueue.top()[1]];
                }
                queryQueue.pop();
            }
            acceptedValue -= queryEnds[i];
        }
        return queryQueue.size();
    }
};
