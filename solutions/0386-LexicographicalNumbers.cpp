class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        int number = 1;
        while(result.size() < n) {
            if(number > n) {
                number /= 10;
                while(number % 10 == 9 || number >= n)
                    number /= 10;
                ++number;
            }
            result.push_back(number);
            number *= 10;
        }
        return result;
    }
};
