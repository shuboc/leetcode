class Solution {
public:
    int numTrees(int n) {
        int num[n+1] = {0};
        num[0] = num[1] = 1;
        // f(k)
        //   \ 
        //    n
        //   / 
        // f(n-1-k)
        // f(n) = sum f(k)f(n-1-k) over k
        for (int i=2; i<=n; ++i) {
            for (int k=0; k<i; ++k) {
                num[i] += num[k] * num[i-1-k];
            }
        }
        
        return num[n];
    }
};