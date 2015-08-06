class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0')
            return 0;
        
        // # for prev digit and prev of prev digit
        int prev = 1, prev_prev = 0;
        for (int i=0; i<s.size(); ++i) {
            int cur = 0; // # for this digit
            
            // If not zero, # for decoding it as a single digit is the same as the prev #
            if (s[i] != '0')
                cur = prev;

            // If the last two digit is also a valid encoding, add prev_prev to the current #
            // For a valid 0, the cur # is the same as prev_prev
            if (i > 0 && s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6')) {
                cur += prev_prev;
            }

            // Update
            prev_prev = prev;
            prev = cur;
        }
        
        return prev;
    }
};