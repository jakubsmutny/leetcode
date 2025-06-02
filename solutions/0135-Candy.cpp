class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<vector<int>> s = getSuccessors(ratings);
        vector<int> order = topSort(s);
        vector<int> candy = vector<int>(s.size(), 1);
        for(int i = 0; i < s.size(); ++i)
            for(const int& successor : s[order[i]])
                candy[successor] = max(candy[order[i]] + 1, candy[successor]);
        int sum = 0;
        for(const int& c : candy) sum += c;
        return sum;
    }

private:
    vector<vector<int>> getSuccessors(vector<int>& ratings) {
        vector<vector<int>> result = vector<vector<int>>(ratings.size(), vector<int>());
        for(int i = 0; i < ratings.size(); ++i) {
            if(i != 0 && ratings[i] < ratings[i-1]) result[i].push_back(i-1);
            if(i != ratings.size() - 1 && ratings[i] < ratings[i+1]) result[i].push_back(i+1);
        }
        return result;
    }

    vector<int> topSort(const vector<vector<int>>& successors) {
        vector<int> result;
        queue<int> Q;
        vector<int> d = vector<int>(successors.size(), 0);
        for(const vector<int>& successorList : successors)
            for(const int& successor : successorList)
                ++d[successor];
        for(int i = 0; i < successors.size(); ++i)
            if(!d[i]) Q.push(i);
        while(!Q.empty()) {
            int z = Q.front(); Q.pop();
            result.push_back(z);
            for(const int& w : successors[z])
                if(--d[w] == 0) Q.push(w);
        }
        for(int i = 0; i < successors.size(); ++i)
            if(d[i]) return vector<int>();
        return result;
    }
};
