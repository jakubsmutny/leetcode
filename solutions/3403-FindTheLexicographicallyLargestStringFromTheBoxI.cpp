class Solution {
public:
    string answerString(string word, int numFriends) {
        if(numFriends == 1) return word;
        int topChar = 0;
        for(int i = 0; i < word.size(); ++i) {
            int cmpSize = word.size() - max(topChar, i);
            for(int j = 0; j < cmpSize; ++j) {
                if(word[i+j] > word[topChar+j]) topChar = i;
                if(word[i+j] != word[topChar+j]) break;
            }
        }
        int endCut = numFriends - 1 - topChar;
        return word.substr(topChar, word.size() - topChar - max(0, endCut));
    }
};
