class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        letterCombinations(digits, "", ret);
        return ret;
    }
    
    void letterCombinations(const string& digits, string str, vector<string>& sol) {
        if (str.size() == digits.size()) {
            sol.push_back(str);
            return;
        }
        
        string letters = digitToLetters(digits[str.size()]);
        for (char letter : letters) {
            letterCombinations(digits, str+letter, sol);
        }
    }
    
    string digitToLetters(const char& digit) {
        switch (digit) {
            case '2':
                return "abc";
            case '3':
                return "def";
            case '4':
                return "ghi";
            case '5':
                return "jkl";
            case '6':
                return "mno";
            case '7':
                return "pqrs";
            case '8':
                return "tuv";
            case '9':
                return "wxyz";
            default:
                return "";
        }
        return "";
    }
};