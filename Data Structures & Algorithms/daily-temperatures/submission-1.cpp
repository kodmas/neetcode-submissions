class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> st;
        int n = temperatures.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            while(true){
                if(st.empty()){
                    st.push({temperatures[i], i});
                    break;
                }
                else{ 
                    pair<int, int> tmp = st.top();
                    if(tmp.first >= temperatures[i]){
                        st.push({temperatures[i], i});
                        break;
                    }
                    else{
                        ans[tmp.second] = i - tmp.second;
                        st.pop();
                    }
                }
            }  
        }
        return ans;
    }
};
