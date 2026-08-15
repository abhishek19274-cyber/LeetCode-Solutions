class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        vector<bool> is_prime(n, true);
        is_prime[0] = false;
        is_prime[1] = false;
        for (long long i = 2; i * i < n; i++) {
            if (is_prime[i]) {
                for (long long j = i * i; j < n; j += i) {
                    is_prime[j] = false;
                }
            }
        }
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (is_prime[i]) {
                count++;
            }
        }
        return count;
    }
};