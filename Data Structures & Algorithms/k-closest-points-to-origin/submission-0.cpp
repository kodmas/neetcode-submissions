class Solution {
private:
    struct CompareDist{
        bool operator()(pair<vector<int>, int> a, pair<vector<int>, int> b){
            return a.second > b.second;
        }
    };
    
public: 
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int x, y;
        vector<vector<int>> ans;
        priority_queue<pair<vector<int>, int>, vector<pair<vector<int>, int>>, CompareDist> mxpq;
        for(auto pt:points){
            x = pt[0];
            y = pt[1];
            mxpq.push(pair<vector<int>, int> (pt, x*x+y*y));
        }

        for(int i=0;i<k;i++){
            pair<vector<int>, int> a = mxpq.top();
            ans.push_back(a.first);
            mxpq.pop();
        }

        return ans;
    }
};
