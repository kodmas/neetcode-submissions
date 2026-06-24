class Solution {
public:
    int maxArea(vector<int>& heights) {
        int ans = 0;

        int i = 0;
        int j = heights.size()-1;
        int currArea = 0;
        while(i < j){
            currArea = min(heights[i], heights[j]) * (j-i);
            if(currArea > ans) ans = currArea;

            if(heights[i] < heights[j]) i++;
            else j--;
        }
        return ans;
    } 
};
