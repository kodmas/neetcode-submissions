class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int pre[n];
        vector<int> ans;
        int curr = 1;
        for(int i=0;i<n;i++){
            pre[i] = curr;
            curr = curr * nums[i];
        }
        curr = 1;
        int suf[n];
        for(int i=n-1;i>=0;i--){
            suf[i] = curr;
            curr = curr * nums[i];
        }

        for(int i=0;i<n;i++){
            ans.push_back(pre[i] * suf[i]);
        }

        return ans;
    }
};
