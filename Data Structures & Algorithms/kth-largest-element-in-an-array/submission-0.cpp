class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // priority_queue<int, vector<int> std::greater<int>> min_pq;
        priority_queue<int> max_pq;
        for(auto it:nums) max_pq.push(it);

        for(int i=0;i<k-1;i++) max_pq.pop();

        return max_pq.top();

    }
};
