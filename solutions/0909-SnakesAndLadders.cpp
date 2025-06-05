class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int s = board.size();
        vector<int> d = vector<int>(s * s, -1);
        queue<int> Q;
        d.front() = 0;
        Q.push(0);
        while(!Q.empty()) {
            int n = Q.front(); Q.pop();
            for(int i = 1; i <= 6; ++i) {
                int m = n + i;
                if(m >= s * s) continue;
                int r = m / s;
                int c = m % s;
                if(r % 2) c = s - 1 - c;
                r = s - 1 - r;
                if(board[r][c] != -1) m = board[r][c] - 1;
                if(d[m] == -1) {
                    d[m] = d[n] + 1;
                    Q.push(m);
                }
            }
            if(d.back() != -1) break;
        }
        return d.back();
    }
};
