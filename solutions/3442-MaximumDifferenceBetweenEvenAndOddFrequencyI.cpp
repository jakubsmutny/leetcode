class Solution {
public:
    int maxDifference(string s) {
        vector<int> f = vector<int>(26, 0);
        for(const char& c : s)
            f[c - 'a']++;
        int a1 = 0;
        int a2 = INT_MAX;
        for(int i = 0; i < 26; i++) {
            if(!f[i]) continue;
            if(f[i] % 2) a1 = max(a1, f[i]);
            else a2 = min(a2, f[i]);
        }
        return a1 - a2;
    }
};
