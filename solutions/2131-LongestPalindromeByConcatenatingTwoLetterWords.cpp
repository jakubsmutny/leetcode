class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        vector<vector<int>> occuranceMatrix = vector<vector<int>>(26, vector<int>(26, 0));
        for(const string& word : words)
            ++occuranceMatrix[word[0] - 'a'][word[1] - 'a'];
        bool middleFilled = false;
        int result = 0;
        for(int i = 0; i < 26; ++i) {
            result += occuranceMatrix[i][i] - occuranceMatrix[i][i] % 2;
            if(!middleFilled && occuranceMatrix[i][i] % 2) {
                middleFilled = true;
                ++result;
            }
            for(int j = i + 1; j < 26; ++j)
                result += 2 * min(occuranceMatrix[i][j], occuranceMatrix[j][i]);
        }
        return result * 2;
    }
};
