class Solution {
public:
    map<int, int> m = {{0,0}, {1,1}, {2, 1}};
    int fib(int n) {
        if (m.find(n) != m.end()) {
            return m[n];
        }
        m[n-1] = fib(n-1);
        m[n-2] = fib(n-2);
        return m[n-1] + m[n-2];
    }
};