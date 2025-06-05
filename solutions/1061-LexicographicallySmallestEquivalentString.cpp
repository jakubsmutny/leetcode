class Node {
public:
    Node(char c) : val(c), next(nullptr) {}
    char val;
    Node* next;
};

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<Node*> repre;
        for(char c = 'a'; c <= 'z'; ++c)
            repre.push_back(new Node(c));
        for(int i = 0; i < s1.size(); ++i) {
            if(s1[i] == s2[i]) continue;
            Node* x1 = repre[s1[i] - 'a'];
            Node* x2 = repre[s2[i] - 'a'];
            while(x1 -> next) x1 = x1 -> next;
            while(x2 -> next) x2 = x2 -> next;
            if(x1 -> val < x2 -> val) x2 -> next = x1;
            if(x1 -> val > x2 -> val) x1 -> next = x2;
        }
        string result;
        for(const char& c : baseStr) {
            Node* x = repre[c - 'a'];
            while(x -> next) x = x -> next;
            result.push_back(x -> val);
        }
        return result;
    }
};
