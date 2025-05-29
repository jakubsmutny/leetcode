class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        vector<vector<int>> s = getSuccessors(edges2.size() + 1, edges2);
        vector<int> evenOdd = evenOddCount(s);
        int value = max(evenOdd[0], evenOdd[1]);
        s = getSuccessors(edges1.size() + 1, edges1);
        evenOdd = evenOddCount(s);
        vector<int> oddNodes = findOdd(s);
        vector<int> answer = vector<int>(s.size(), value + evenOdd[0]);
        for(const int& oddNode : oddNodes) answer[oddNode] = value + evenOdd[1];
        return answer;
    }

    vector<vector<int>> getSuccessors(int nodes, const vector<vector<int>>& edges) {
        vector<vector<int>> result = vector<vector<int>>(nodes, vector<int>());
        for(const vector<int>& edge : edges) {
            result[edge[0]].push_back(edge[1]);
            result[edge[1]].push_back(edge[0]);
        }
        return result;
    }

    vector<int> evenOddCount(const vector<vector<int>>& successors) {
        int odd = 0;
        int even = 0;
        vector<int> d = vector<int>(successors.size(), -1);
        queue<int> Q;
        d[0] = 0;
        Q.push(0);
        while(!Q.empty()) {
            int n = Q.front(); Q.pop();
            if(d[n] % 2) ++odd;
            else ++even;
            for(int m : successors[n])
                if(d[m] == -1) {
                    d[m] = d[n] + 1;
                    Q.push(m);
                }
        }
        return vector<int>({even, odd});
    }

    vector<int> findOdd(const vector<vector<int>>& successors) {
        vector<int> result;
        vector<int> d = vector<int>(successors.size(), -1);
        queue<int> Q;
        d[0] = 0;
        Q.push(0);
        while(!Q.empty()) {
            int n = Q.front(); Q.pop();
            if(d[n] % 2) result.push_back(n);
            for(int m : successors[n])
                if(d[m] == -1) {
                    d[m] = d[n] + 1;
                    Q.push(m);
                }
        }
        return result;
    }
};
