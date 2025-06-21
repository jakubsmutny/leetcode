class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> o = vector<int>(26, 0);
        for(const char& c : word) o[c - 'a']++;
        int result = INT_MAX;
        for(int i = 0; i < 26; i++) {
            int deletions = 0;
            for(int j = 0; j < 26; j++) {
                if(o[j] < o[i]) deletions += o[j];
                if(o[j] - o[i] > k) deletions += o[j] - (o[i] + k);
            }
            result = min(result, deletions);
        }
        return result;
    }
};
