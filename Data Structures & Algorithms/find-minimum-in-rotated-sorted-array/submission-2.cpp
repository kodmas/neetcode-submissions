class Solution {
public:
    int findMin(vector<int> &nums) {
        int first = nums[0];
        int last = nums[nums.size()-1];

        int l = 0, r = nums.size()-1;
        int mid;
        while(l <= r){
            mid = (l+r)/2;
            if(nums[mid] > nums[mid+1]) return nums[mid+1];
            else{
                if(nums[mid+1] > last) l = mid+1;
                else r = mid-1;
            }
        }

        return first;
    }
};
