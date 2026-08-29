class Solution {
public:
    void dfs(const vector<int>& nums, int i,  int& cur_sum, int target, vector<int>& sol, vector<vector<int>>& ans){
        if(cur_sum > target) return;
        else if(cur_sum == target){
            ans.push_back(sol);
            return;
        }
        else{
            for(int j=i;j<nums.size();j++){
                sol.push_back(nums[j]);
                cur_sum += nums[j];
                dfs(nums, j, cur_sum, target, sol, ans);
                sol.pop_back();
                cur_sum -= nums[j];
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> sol;
        int cur_sum = 0;
        dfs(nums, 0, cur_sum, target, sol, ans);

        return ans;
    }
};

