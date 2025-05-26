class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        vector<vector<int>> successors = getSuccessors(colors.size(), edges);
        vector<int> order = topSort(colors.size(), edges, successors);
        if(order.size() != colors.size()) return -1;
        int maximum = 0;
        vector<vector<int>> table = vector<vector<int>>(order.size(), vector<int>(26, 0));
        for(int i = order.size() - 1; i >= 0; --i) {
            for(const int& successor : successors[order[i]])
                for(int a = 0; a < 26; ++a)
                    table[order[i]][a] = max(table[order[i]][a], table[successor][a]);
            ++table[order[i]][colors[order[i]] - 'a'];
            maximum = max(maximum, table[order[i]][colors[order[i]] - 'a']);
        }
        return maximum;
    }

private:
    vector<vector<int>> getSuccessors(int nodes, const vector<vector<int>>& edges) {
        vector<vector<int>> result = vector<vector<int>>(nodes, vector<int>());
        for(const vector<int>& edge : edges)
            result[edge[0]].push_back(edge[1]);
        return result;
    }

    vector<int> topSort(int nodes, const vector<vector<int>>& edges,
                        const vector<vector<int>>& successors) {
        vector<int> result;
        queue<int> Q;
        vector<int> d = vector<int>(nodes, 0);
        for(const vector<int>& edge : edges)
            ++d[edge[1]];
        for(int i = 0; i < nodes; ++i)
            if(!d[i]) Q.push(i);
        while(!Q.empty()) {
            int z = Q.front(); Q.pop();
            result.push_back(z);
            for(const int& w : successors[z])
                if(--d[w] == 0) Q.push(w);
        }
        for(int i = 0; i < nodes; ++i)
            if(d[i]) return vector<int>();
        return result;
    }
};
