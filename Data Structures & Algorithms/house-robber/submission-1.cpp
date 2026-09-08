class Solution {
public:
    int rob(vector<int>& nums) {
        // int n = nums.size();
        // vector<int> dp(3);
        
        // if(n == 1) return nums[0];
        // if(n == 2) return max(nums[0], nums[1]);
        // if(n == 3) return max((nums[0] + nums[2]), nums[1]); 

        // dp[0] = nums[0];
        // dp[1] = nums[1];
        // dp[2] = max(nums[0] + nums[2], nums[1]);
        // int cur;
        // for(int i=3;i<n;i++){
        //     cur = max({(nums[i] + dp[0]), (nums[i] + dp[1]), dp[2]});
        //     dp[0] = dp[1];
        //     dp[1] = dp[2];
        //     dp[2] = cur;
        // }

        // return cur;
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];

        vector<int> dp(nums.size());
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < nums.size(); i++) {
            dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
        }

        return dp[nums.size() - 1];
    }
};
