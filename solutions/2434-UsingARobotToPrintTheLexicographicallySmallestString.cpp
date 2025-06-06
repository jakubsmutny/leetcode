class Solution {
public:
    string robotWithString(string s) {
        vector<int> charCount = vector<int>(26, 0);
        for(const char& c : s)
            ++charCount[c - 'a'];
        stack<char> t;
        string result;
        int j = 0;
        while(j < s.size()) {
            char smallest = smallestChar(charCount);
            if(smallest == '0') break;
            while((t.empty() || t.top() > smallest) && j < s.size()) {
                t.push(s[j]);
                --charCount[s[j] - 'a'];
                ++j;
            }
            result += t.top(); t.pop();
        }
        while(!t.empty()) {
            result += t.top();
            t.pop();
        }
        return result;
    }

private:
    char smallestChar(const vector<int>& charCount) {
        for(int i = 0; i < charCount.size(); ++i)
            if(charCount[i]) return 'a' + i;
        return '0';
    }
};
