class Solution {
public:
    int countGoodArrays(int n, int m, int k) {
        long result = m;
        const int modul = pow(10, 9) + 7;
        result = (result * combinationsModulo(n - 1, k, modul)) % modul;
        result = (result * powerModulo(m - 1, n - k - 1, modul)) % modul;
        return result;
    }

    int combinationsModulo(int n, int k, int m) {
        if (k > n) return 0;
        if (k * 2 > n) k = n - k;
        long result = 1;
        for(int i = 1; i <= k; i++ ) {
            result = (result * (n - i + 1)) % m;
            result = (result * powerModulo(i, m - 2, m)) % m;
        }
        return result;
    }

    int powerModulo(int n, int e, int m) {
        if(!e) return 1;
        long result = powerModulo(n, e / 2, m);
        result = (result * result) % m;
        if(e % 2) result = (n * result) % m;
        return result;
    }
};
