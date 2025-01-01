class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, h = s.length() - 1;
        transform(s.begin(), s.end(), s.begin(), ::tolower); 
        while (l < h) {
            while (l < h && !isalnum(s[l]))
                l++;
            while (l < h && !isalnum(s[h]))
                h--;
            // cout << s[l] << " " << s[h] << "\n";
            if (s[l] != s[h])
                return false;
            l++;
            h--;
        }
        return true;
    }
};