class Solution {
public:
    string triangleType(vector<int>& nums) {
        bubbleSort(nums);
        if(nums[0] + nums[1] <= nums[2]) return "none";
        if(nums[0] == nums[1] && nums[1] == nums[2]) return "equilateral";
        if(nums[0] == nums[1] || nums[1] == nums[2]) return "isosceles";
        return "scalene";
    }

private:
    void bubbleSort(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++)
            for(int j = 0; j < nums.size() - 1; j++)
                if(nums[j] > nums[j + 1]) {
                    int swapHelp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = swapHelp;
                }
    }
};
