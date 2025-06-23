class Solution {
public:
    // Check if string s is palindrome
    bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while(l < r) {
            if(s[l++] != s[r--]) return false;
        }
        return true;
    }

    // Convert number to base-k and return as string
    string toBase(long long num, int k) {
        string res = "";
        while(num > 0) {
            res += to_string(num % k);
            num /= k;
        }
        reverse(res.begin(), res.end());
        return res;
    }

    // Generate palindromic numbers of 'len' digits
    void generatePalindrome(int len, int k, int n, long long& count, long long& sum) {
        int halfLen = (len + 1) / 2;
        long long start = pow(10, halfLen - 1);
        long long end = pow(10, halfLen);

        for(long long i = start; i < end; i++) {
            string half = to_string(i);
            string full = half;

            // Create full palindrome
            string rev = half;
            reverse(rev.begin(), rev.end());

            if(len % 2 == 1) rev = rev.substr(1); // remove middle if odd length
            full += rev;

            long long num = stoll(full);

            string baseK = toBase(num, k);
            if(isPalindrome(baseK)) {
                sum += num;
                count++;
                if(count == n) return;
            }
        }
    }

    long long kMirror(int k, int n) {
        long long count = 0, sum = 0;
        int len = 1;

        while(count < n) {
            generatePalindrome(len, k, n, count, sum);
            len++;
        }

        return sum;
    }
};
