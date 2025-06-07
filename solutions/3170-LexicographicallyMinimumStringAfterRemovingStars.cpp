class Solution {
public:
    string clearStars(string s) {
        vector<stack<int>> stacks = vector<stack<int>>(26, stack<int>());
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == '*')
                for(stack<int>& stack : stacks) {
                    if(stack.empty()) continue;
                    s[stack.top()] = '*';
                    stack.pop();
                    break;
                }
            else stacks[s[i] - 'a'].push(i);
        }
        erase(s, '*');
        return s;
    }
};
