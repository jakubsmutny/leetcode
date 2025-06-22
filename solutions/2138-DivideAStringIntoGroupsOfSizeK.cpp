class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> result;
        string group;
        for(const char& c : s) {
            group += c;
            if(group.size() == k) {
                result.push_back(group);
                group.clear();
            }
        }
        if(group.empty()) return result;
        while(group.size() != k) group += fill;
        result.push_back(group);
        return result;
    }
};
