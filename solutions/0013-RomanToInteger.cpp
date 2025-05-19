class Solution {
public:
    int romanToInt(string s) {
        if(s.empty()) return 0;
        char mostValuable = getMostValuableSymbol(s);
        int i = s.find(mostValuable);
        string pre = s.substr(0, i);
        string post = s.substr(i + 1);
        return value[mostValuable] - romanToInt(pre) + romanToInt(post);
    }

private:
    inline static map<char, int> value = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

    char getMostValuableSymbol(const string& s) {
        char mostValuable = 'I';
        for(const char& c : s)
            if(value[c] > value[mostValuable])
                mostValuable = c;
        return mostValuable;
    }
};
