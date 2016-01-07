class Solution {
public:
    int minDistance(string word1, string word2) {
        size_t m = word1.size(), n = word2.size();

        // d[i][j]: edit distance between word1[0:i-1] and word2[0:j-1]
        int d[m+1][n+1];
        for (int i = 0; i < m+1; ++i) d[i][0] = i; // Initialization
        for (int j = 0; j < n+1; ++j) d[0][j] = j; // d[i][0] represents the distance (= i) to an empty string

        for (int i = 1; i < m+1; ++i) {
            for (int j = 1; j < n+1; ++j) {
                d[i][j] = min(min(d[i-1][j] + 1, d[i][j-1] + 1), d[i-1][j-1] + (word1[i-1] == word2[j-1] ? 0 : 1));
            }
        }

        return d[m][n];
    }
};

// Linear space
class Solution {
public:
    int minDistance(string word1, string word2) {
        size_t m = word1.size(), n = word2.size();

        int d[2][n+1];
        for (int j = 0; j < n+1; ++j) d[0][j] = j; // Initialization

        for (int i = 1; i < m+1; ++i) {
            d[1][0] = i;
            for (int j = 1; j < n+1; ++j) {
                d[1][j] = min(min(d[1][j-1] + 1, d[0][j] + 1), d[0][j-1] + (word1[i-1] == word2[j-1] ? 0 : 1));
            }

            for (int j = 0; j < n+1; ++j) d[0][j] = d[1][j]; // Swap
        }

        return d[0][n];
    }
};
