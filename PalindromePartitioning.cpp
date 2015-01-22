class Solution {
    vector<vector<string>> ret;
public:
    vector<vector<string>> partition(string s) {
        vector<string> partition;
        getPartition(s, 0, partition);
        return ret;
    }
    
    // Get a partition by recursively checking if s[start:i] is a palindrome and add to the partition.
    // Return if the recursion reaches the end of the string.
    void getPartition(const string& s, int start, vector<string>& partition) {
        if (start == s.size()) {
            ret.push_back(partition);
            return;
        }
        
        for (int i=start; i<s.size(); ++i) {
            if (isPalindrome(s, start, i)) {
                partition.push_back(s.substr(start, i-start+1));
                getPartition(s, i+1, partition);
                partition.pop_back();
            }
        }
    }
    
    bool isPalindrome(string s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end])
                return false;
            ++start;
            --end;
        }
        return true;
    }
};