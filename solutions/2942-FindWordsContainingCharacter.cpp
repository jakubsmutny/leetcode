class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> result;
        for(int i = 0; i < words.size(); ++i)
            if(words[i].contains(x))
                result.push_back(i);
        return result;
    }
};
