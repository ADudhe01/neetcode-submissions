class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxWater = 0;
        int l = 0;
        int r = heights.size() - 1;

        while (l < r) {
            maxWater = max(maxWater, (r - l) * min(heights[l], heights[r]));

            if (heights[l] < heights[r]) l++;
            else r--;
        }

        return maxWater;
    }
};
