class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;

        int ans = 0;
        int i = 0;
        int j = 1;
        int cur;
        while(j < prices.size()){
            if(prices[i] > prices[j]){
                i = j;
                j++;
            }
            else{
                cur = prices[j] - prices[i];
                if(cur > ans) ans = cur;
                j++;
            }
        }

        return ans;

    }
};
