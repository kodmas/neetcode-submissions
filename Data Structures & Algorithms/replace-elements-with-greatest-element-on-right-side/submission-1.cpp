class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> ans(arr.size(), -1);
        int max = arr[arr.size()-1];
        for(int i=arr.size()-2;i>=0;i--){
            ans[i] = max;
            if(arr[i] > max){
                max = arr[i];
            }
        }
        return ans;
    }
};