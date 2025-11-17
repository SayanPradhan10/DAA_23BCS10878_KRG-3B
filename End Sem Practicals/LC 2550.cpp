class Solution {
public:
    int monkeyMove(int n) {
        long long mod = 1000000007;
        long long base = 2;
        long long result = 1;

       
        while (n > 0) {
            if (n % 2 == 1) result = (result * base) % mod;
            base = (base * base) % mod;
            n /= 2;
        }

        result = (result - 2 + mod) % mod;

        return result;
    }
};
