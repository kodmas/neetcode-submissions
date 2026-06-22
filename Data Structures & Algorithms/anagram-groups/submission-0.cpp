class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int len = strs.size();
        vector<vector<string>> ans;
        map<array<int, 26>, int> mem;

        int index = 0;
        for(auto str:strs){
            array<int, 26> freq = {};
            for(auto c:str) freq[c-'a']++;

            if(mem.find(freq) == mem.end()){
                mem.insert(pair<array<int, 26>, int>(freq, index));
                index++;
                ans.push_back({str});
            }
            else{
                ans[mem[freq]].push_back(str);
            }
        }
        return ans;   
    }
};