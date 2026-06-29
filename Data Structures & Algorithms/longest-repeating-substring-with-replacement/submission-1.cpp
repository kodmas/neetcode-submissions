class Solution {
public:
    int characterReplacement(string s, int k) {
        int i = 0;
        int j = 0;
        int ans = 0;
        int cur = 1;
        int max_fre = 1;
        map<char, int> mem;
        while(j < s.size()){
            if(!mem.count(s[j])) mem.insert(pair<char, int>(s[j] ,1));
            else mem[s[j]]++;
            // for(auto& [key, value]:mem) cout << key << " " << value << endl;
            // cout << endl;
            if(mem[s[j]] > max_fre) max_fre = mem[s[j]];
            // cout << i << " " << j << " " << max_fre << endl;
            if((j-i+1) - max_fre <= k){
                cur = (j-i+1);
                if(cur > ans) ans = cur;
            }
            else{
                if(mem[s[i]] == max_fre) max_fre--;
                mem[s[i]]--;
                if(mem[s[i]] == 0){
                    mem.erase(s[i]);
                }
                i++;
            }
            j++;
        }

        return ans;
    }
};
