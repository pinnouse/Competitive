class Solution {
public:
    int reverse(int x) {
        long n = 0;
        bool neg = x < 0;
        if (x == -2147483648) return 0;
        if (neg) x = -x;
        if (x == 0) return x;
        int c = floor(log10(abs(x)));
        for (int i = 0; i <= c; ++i) {
            long m = n;
            for (int j = 0; j < 9; ++j) {
                n += m;
            }
            n += (x / int(pow(10, i))) % 10;
            if (n > 2147483648) return 0;
        }
        if (neg && n > 0) n = -n;
        return n;
    }
};