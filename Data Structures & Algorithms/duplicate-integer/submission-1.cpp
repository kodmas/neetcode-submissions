class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> mem;
        for(auto i:nums){
            if(mem.count(i) == 0) mem.insert(i);
            else return true;
        }
        return false;
    }
};