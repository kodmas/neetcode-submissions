class Solution {
public:
    void dfs(vector<int>& candidates, int target, int start,
             vector<int>& sol, vector<vector<int>>& ans) {

        if (target == 0) {
            ans.push_back(sol);
            return;
        }

        for (int j = start; j < candidates.size(); j++) {

            if (j > start && candidates[j] == candidates[j - 1])
                continue;

            if (candidates[j] > target)
                break;

            sol.push_back(candidates[j]);

            dfs(candidates, target - candidates[j],
                j + 1, sol, ans);

            sol.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> sol;

        dfs(candidates, target, 0, sol, ans);

        return ans;
    }
};