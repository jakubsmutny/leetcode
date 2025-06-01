class Solution {
public:
    long long distributeCandies(int n, int limit) {
        if(n > limit * 3) return 0;
        long long result = 0;
        for(int i = 0; i <= min(n, limit); ++i) {
            int m = n - i;
            if(limit * 2 < m) continue;
            result += min(m, limit) * 2 - m + 1;
        }
        return result;
    }
};
