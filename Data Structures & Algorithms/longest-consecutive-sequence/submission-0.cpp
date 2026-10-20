class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int ans = 1;


        unordered_map<int, int> mem;


        for(auto& it:nums){
            if(!mem[it]){
                mem[it] = mem[it - 1] + mem[it + 1] + 1;
                mem[it - mem[it - 1]] = mem[it];
                mem[it + mem[it + 1]] = mem[it];
                ans = max(ans, mem[it]);
            }
        }

        return ans;
    }
};
