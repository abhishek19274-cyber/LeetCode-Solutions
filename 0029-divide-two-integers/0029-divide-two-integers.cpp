class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;

        bool isPositive = (dividend > 0) == (divisor > 0);

        long long n = abs((long long)dividend);
        long long d = abs((long long)divisor);
        long long ans = 0;

        for (int i = 31; i >= 0; i--) {
            if ((n >> i) >= d) {
                ans += (1LL << i);
                n -= (d << i);
            }
        }

        return isPositive ? (int)ans : (int)-ans;
    }
};