class Solution {
public:
    int findKthNumber(int n, int k) {
        n++; k--;
        int number = 1;
        while(k) {
            int c = prefixNums(n, number);
            if(c > k) {
                k--;
                number *= 10;
            } else {
                k -= c;
                number++;
            }
        }
        return number;
    }

private:
    int prefixNums(int n, int prefix) {
        int zeros = pow(10, floor(log10f(n) + 1) - floor(log10f(prefix) + 1));
        int result = 0;
        for(int i = 1; i < zeros; i *= 10)
            result += i;
        if(prefix * zeros < n)
            result += min(zeros, n - prefix * zeros);
        return result;
    }
};
