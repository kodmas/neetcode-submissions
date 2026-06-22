class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int, int> mem;
        for(auto it:nums){
            mem[it] = 1 + mem[it];
        }

        // Important: create frequency map so that freq[i] = vector of all numbers that exists i times

        vector<vector<int>> freq(nums.size()+1);

        for(auto data:mem) freq[data.second].push_back(data.first);

        for(int i=freq.size()-1;i>=0;i--){
            for(auto it:freq[i]){
                ans.push_back(it);
                if(ans.size() == k) return ans;
            }
        }

        return ans;
    }
};
