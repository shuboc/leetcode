class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        if (n < 1) 
            return 0;
            
        int upper = n-1;
        int lower = 0;
     
        while ( lower <= upper) {
            int mid = (upper + lower) / 2;
            if (A[mid] == target)
                return mid;
            if ((mid + 1 < n) && (A[mid] < target) && (A[mid+1] > target))
                return mid + 1;
            if (A[mid] < target)
                lower = mid + 1;
            else if (A[mid] > target) 
                upper = mid - 1;
        }
        return lower;
    }
};