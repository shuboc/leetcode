class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        digits[digits.size() - 1] += 1;
        // Carry
        for (int i = digits.size() - 1; i >= 0; --i) {
            if (digits[i] > 9) {
                digits[i] = digits[i] % 10;
                if (i > 0)
                    digits[i-1] += 1;
                else
                    digits.insert(digits.begin(), 1);
            }
        }
        
        return digits;
    }
};