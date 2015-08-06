class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.empty())
            return 0;
        
        // Record current pMin and pMax
        // There will be a possible new
        int bestProf = 0, pMin = prices[0], pMax = prices[0];
        
        for (int i=1; i<prices.size(); ++i) {
            if (prices[i] < pMin) {
                bestProf = max(bestProf, pMax-pMin);
                pMin = pMax = prices[i];
            } else if (prices[i] > pMax) {
                pMax = prices[i];
            }
        }
        
        bestProf = max(bestProf, pMax-pMin);
        return bestProf;
    }
};