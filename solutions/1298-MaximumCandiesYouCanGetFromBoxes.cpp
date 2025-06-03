class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys,    
                   vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int totalCandies = 0;
        queue<int> opened;
        set<int> owned;
        for(const int& box : initialBoxes) {
            if(status[box]) opened.push(box);
            else owned.insert(box);
        }
        while(!opened.empty()) {
            int n = opened.front(); opened.pop();
            totalCandies += candies[n];
            for(const int& key : keys[n]) {
                status[key] = 1;
                if(owned.contains(key)) {
                    opened.push(key);
                    owned.erase(key);
                }
            }
            for(const int& box : containedBoxes[n]) {
                if(status[box]) opened.push(box);
                else owned.insert(box);
            }
        }
        return totalCandies;
    }
};
