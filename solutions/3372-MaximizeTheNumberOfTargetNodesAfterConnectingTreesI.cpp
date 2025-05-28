class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        vector<vector<int>> s = getSuccessors(edges2.size() + 1, edges2);
        int bonus = 0;
        for(int i = 0; i < s.size(); ++i)
            bonus = max(bonus, reachableOverDistance(i, s, k - 1));
        s = getSuccessors(edges1.size() + 1, edges1);
        vector<int> answer;
        for(int i = 0; i < s.size(); ++i)
            answer.push_back(bonus + reachableOverDistance(i, s, k));
        return answer;
    }

private:
    vector<vector<int>> getSuccessors(int nodes, const vector<vector<int>>& edges) {
        vector<vector<int>> result = vector<vector<int>>(nodes, vector<int>());
        for(const vector<int>& edge : edges) {
            result[edge[0]].push_back(edge[1]);
            result[edge[1]].push_back(edge[0]);
        }
        return result;
    }

    int reachableOverDistance(int start, const vector<vector<int>>& successors, int distance) {
        int result = 0;
        vector<int> d = vector<int>(successors.size(), -1);
        queue<int> Q;
        d[start] = 0;
        Q.push(start);
        while(!Q.empty()) {
            int n = Q.front(); Q.pop();
            if(d[n] <= distance) ++result;
            if(d[n] >= distance) continue;
            for(int m : successors[n])
                if(d[m] == -1) {
                    d[m] = d[n] + 1;
                    Q.push(m);
                }
        }
        return result;
    }
};
