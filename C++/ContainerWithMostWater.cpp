class Solution {
public:
    int maxArea(vector<int> &height) {
        int maxWater = 0;
        int start = 0, end = height.size() - 1;
        while (start < end) {
            int water = (end - start) * min(height[start], height[end]);
            maxWater = max(maxWater, water);
            if (height[start] < height[end])
                ++start;
            else
                --end;
        }
        
        return maxWater;
    }
};