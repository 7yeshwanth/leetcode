map<char, string> m = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"},
                       {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
                       {'8', "tuv"}, {'9', "wxyz"}};

void u(vector<string>& result, string digits,int n, int index, string pre) {
    if (index == n){
        result.push_back(pre);
        return ;
    }
    for(char i: m[digits[index]]){
        u(result, digits, n, index+1, pre+i);
    }
}


class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        if(n == 0) return {};
        vector<string> result;
        u(result, digits, n, 0, "");
        return result;
    }
};