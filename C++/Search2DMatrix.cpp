class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        size_t m = matrix.size(), n = matrix[0].size();

        // Binary search
        int start = 0, end = m * n - 1, mid = (start + end) / 2;
        while (start <= end) {
            int val = matrix[mid / n][mid % n];

            if (val == target) break;
            else if (val > target) end = mid - 1;
            else start = mid+1;

            mid = (start + end) / 2;
        }

        return (matrix[mid / n][mid % n] == target);
    }
};