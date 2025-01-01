class Solution {
public:
    vector<int> plusOne(vector<int>& digits, int index = -2) {
        if (index == -2)
        {
            index = digits.size() - 1;
        }
        if (index == -1)
        {
            digits.insert(digits.begin(), 1);
            return digits;
        }
        digits[index]++;
        if (digits[index] == 10)
        {
            digits[index] = 0;
            plusOne(digits, index - 1);
        }
        return digits;
    }
};