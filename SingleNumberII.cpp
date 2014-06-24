class Solution {
public:
    int singleNumber(int A[], int n) {
        int ones = 0; // Sums of numbers that shows 1 time.
        int twos = 0; // Sums of numbers that shows 2 times.
        for (int i = 0; i < n; ++i) {
            twos |= (ones & A[i]);
            ones ^= A[i];
            int threes = (twos & ones); // The number which shows 3 times.
            ones &= ~threes;
            twos &= ~threes;
        }
        return ones;
    }
};