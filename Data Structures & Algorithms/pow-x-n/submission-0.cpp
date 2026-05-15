class Solution {
public:
    double recur(double x, int n) {
        if (n == 0) return 1.0;

        return x * recur(x, n - 1);
    }

    double myPow(double x, int n) {
        if (x == 0) return 0.0;
        if (n < 0) return 1.0 / recur(x, abs(n));

        return recur(x, n);
    }
};
