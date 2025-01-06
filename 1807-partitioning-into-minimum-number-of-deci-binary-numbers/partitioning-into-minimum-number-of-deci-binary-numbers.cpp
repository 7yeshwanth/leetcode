class Solution {
public:
    int minPartitions(string n) {
        int m = -1;
        for(char c:n)
        {
            m = max(m, int(c-'0'));
        }
        return m; 
    }
};