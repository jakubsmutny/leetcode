class NumWithIndex {
public:
    int index;
    int value;
    NumWithIndex(int i, int v) : index(i), value(v) {}
    bool operator<(const NumWithIndex &other) const {
        return value < other.value;
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<NumWithIndex> indexedNums = vector<NumWithIndex>();
        for(int i = 0; i < nums.size(); ++i)
            indexedNums.push_back(NumWithIndex(i, nums[i]));
        sort(indexedNums.begin(), indexedNums.end());
        int forward = 0;
        int backward = indexedNums.size() - 1;
        while(true) {
            int front = indexedNums[forward].value;
            int back = target - indexedNums[backward].value;
            if(front == back) break;
            if(front < back) ++forward;
            if(front > back) --backward;
            // if(forward >= backward) return vector<int>();
        }
        int a = indexedNums[forward].index;
        int b = indexedNums[backward].index;
        return vector<int>({min(a, b), max(a, b)});
    }
};
