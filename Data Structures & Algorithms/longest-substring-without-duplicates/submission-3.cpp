class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;
        // else if(s.size() == 0) return 
        int ans = 0;

        int cur = 1;

        int i = 0;
        int j = 1;
        map<char, int> mem;
        mem.insert(pair<char, int>(s[i], 0));
        while(j < s.size()){
           if(mem.count(s[j])){
                mem.erase(s[i]);                         
                ans = max(cur, ans);
                cur--;
                i++;
           } 
           else{
                mem.insert(pair<char, int>(s[j], j));
                cur++;
                j++;
           }
        }
        ans = max(ans, cur);
        return ans;
    }
};
