class Solution {
public:
    bool isValid(string s) {
        stack<int> stack;
        for(const char& c : s) {
            if(value[c] > 2) {
                if(!value.contains(c)) return false;
                if(stack.empty() || stack.top() != value[c]) return false;
                stack.pop();
            }
            else stack.push(value[c] + 3);
        }
        return stack.empty();
    }

private:
    inline static map<char, int> value = {
        {'(', 0}, {')', 3},
        {'{', 1}, {'}', 4},
        {'[', 2}, {']', 5},
    };
};
