class Solution {
public:
    map<int, int> m;
    int fib(int n) {
        if (m.find(n) != m.end()) {
            return m[n];
        }
        if (n == 0) {
            return 0;
        }
        if (n <= 2) {
            return 1;
        }
        return fib(n - 1) + fib(n - 2);
    }
};