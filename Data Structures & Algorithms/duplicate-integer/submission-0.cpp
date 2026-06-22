class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map<int, int> mem;
        for(auto i:nums){
            if(mem.count(i) == 0) mem.insert(pair<int, int>(i, 1));
            else return true;
        }
        return false;
    }
};