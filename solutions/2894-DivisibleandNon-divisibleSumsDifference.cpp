class Solution {
public:
    int differenceOfSums(int n, int m) {
        int sum = n * (n + 1) / 2;
        int sub = (n / m) * ((n - n % m) + (m <= n ? m : 0)) / 2;
        return sum - sub * 2;
    }
};
