class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if (words.empty()) {
            return ans;
        }

        const int W = words.size(), L = words[0].size(), S = s.size();

        // We use a reference map and an current map of word counts to track valid concatenations.
        typedef unordered_map<string, int> Map;
        Map expectedCount;
        for (int i = 0; i < W; ++i) {
            if (expectedCount.find(words[i]) == expectedCount.end()) {
                expectedCount[words[i]] = 0;
            }
            expectedCount[words[i]] += 1;
        }

        // We check a word of length L through the whole string, one at a time.
        // Only need to test for L different starting points.
        // The time complexity would be O(LS).

        for (int i = 0; i < L; ++i) {
            // The total word count of the current concatenation
            int count = 0;

            // The start point of the current concatenation
            int start = i;

            Map currentCount;
            for (int j = i; j <= S - L; j += L) {
                string word = s.substr(j, L);
                // Not found => bad concatenation
                if (expectedCount.find(word) == expectedCount.end()) {
                    currentCount.clear();
                    count = 0;
                    start = j + L;
                    continue;
                }

                // Update current count
                if (currentCount.find(word) == currentCount.end()) {
                    currentCount[word] = 1;
                } else {
                    ++currentCount[word];
                }

                // Remove all words before last same word as this to make a valid concatenation
                if (currentCount[word] > expectedCount[word]) {
                    string toRemove;
                    do {
                        toRemove = s.substr(start, L);
                        --currentCount[toRemove];
                        --count;
                        start += L;
                    } while (toRemove != word);
                }

                if (++count == W) {
                    ans.push_back(start);
                }
            }
        }

        return ans;
    }
};