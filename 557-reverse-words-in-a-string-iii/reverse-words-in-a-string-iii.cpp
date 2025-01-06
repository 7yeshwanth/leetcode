class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string w, r;
        while (ss >> w) {
            reverse(w.begin(), w.end());
            r += w + " ";
        }
        return r.substr(0, s.size());
    }
};