class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> max_pq;
        for(auto st:stones) max_pq.push(st);
        int a, b;
        while(max_pq.size() > 1){
            a = max_pq.top();
            max_pq.pop();
            b = max_pq.top();
            max_pq.pop();

            if(a == b){
                if(max_pq.size() == 0) return 0;
            }
            else max_pq.push(max(a,b) - min(a,b));
        }

        return max_pq.top();
    }
};
