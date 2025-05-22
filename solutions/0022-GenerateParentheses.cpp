class Solution {
public:
    vector<string> result;
    string str;

    vector<string> generateParenthesis(int n) {
        recursive(n, n);
        return result;
    }
    
    void recursive(int o, int c) {
        if(o) {str += '('; recursive(o - 1, c); str.pop_back();}
        if(c && o < c) {str += ')'; recursive(o, c - 1); str.pop_back();}
        if(!o && !c) result.push_back(str);
    }
};
