class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int j, k;
        vector<vector<int>> ans;
        
        for(int i=0;i<nums.size()-2;i++){
            if(i != 0 && nums[i] == nums[i-1]) continue;
            j = i+1;
            k = nums.size()-1;
            while(j<k){
                if(-nums[i] < (nums[j] + nums[k])) k--;
                else if(-nums[i] > (nums[j] + nums[k])) j++;
                else{
                    vector<int> found = {nums[i], nums[j], nums[k]};
                    ans.push_back(found);
                    j++;
                    k--;
                    while(nums[j] == nums[j-1] && j < nums.size()-1) j++;
                    while(nums[k] == nums[k+1] && k > 0) k--;
                }
            }
        }
        // ans.erase(std::unique(ans.begin(), ans.end()), ans.end());

        return ans;
    }
};
