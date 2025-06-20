class Solution {
public:
    int maxDistance(string s, int k) {
        int result = 0;
        for(int i = 0; i < 4; i++) {
                int x = 0;
                int y = 0;
                int d = 0;
                for(const char& c : s) {
                    int dir = value[c];
                    if(d < k && (dir == i || (dir + 1) % 4 == i)) {
                        dir = (dir + 2) % 4;
                        d++;
                    }
                    switch(dir) {
                        case 0: y++; break;
                        case 1: x++; break;
                        case 2: y--; break;
                        case 3: x--; break;
                    }
                    result = max(result, abs(x) + abs(y));
                }
            }
        return result;
    }

private:
    inline static map<char, int> value = {
        {'N', 0},
        {'E', 1},
        {'S', 2},
        {'W', 3}
    };
};
