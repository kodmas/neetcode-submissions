class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mem;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(mem.count(target-nums[i]) == 0) mem.insert(pair<int, int>(nums[i], i));
            else{
                ans.push_back(mem[target-nums[i]]);
                ans.push_back(i);
                break;
            }
        }
        return ans;
    }
};
