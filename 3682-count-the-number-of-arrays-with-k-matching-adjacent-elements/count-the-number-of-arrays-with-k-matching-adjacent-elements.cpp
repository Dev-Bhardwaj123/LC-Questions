class Solution {
public:
    int countGoodArrays(int n, int m, int k) {
        const int mod = 1'000'000'007;
        int d = n - 1;
        if (k > d) return 0;
        int r = k;
        if (r > d - r) r = d - r;
        long long C = 1;
        if (r) {
            vector<int> inv(r+1);
            inv[1] = 1;
            for (int i = 2; i <= r; ++i) {
                inv[i] = (long long)(mod - mod/i) * inv[mod%i] % mod;
            }
            for (int i = 1; i <= r; ++i) {
                C = C * (d - r + i) % mod;
                C = C * inv[i] % mod;
            }
        }
        auto modpow = [&](long long base, int exp) {
            long long res = 1;
            while (exp) {
                if (exp & 1) res = res * base % mod;
                base = base * base % mod;
                exp >>= 1;
            }
            return res;
        };
        return int(((long long)(m) * C % mod) * modpow(m - 1, d - k) % mod);
    }
};