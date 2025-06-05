class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source == destination) return true;
        vector<vector<int>> s = getSuccessors(n, edges);
        vector<bool> d = vector<bool>(n, false);
        queue<int> Q;
        d[source] = true;
        Q.push(source);
        while(!Q.empty()) {
            int n = Q.front(); Q.pop();
            for(int m : s[n])
                if(!d[m]) {
                    if(m == destination) return true;
                    d[m] = true;
                    Q.push(m);
                }
        }
        return false;
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
};
