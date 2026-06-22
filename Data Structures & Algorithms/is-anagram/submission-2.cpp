class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        map<char, int> mem;

        for(auto it:s){
            if(mem.count(it)) mem[it]++;
            else mem.insert(pair<char, int>(it, 1));
        }

        for(auto it:t){
            if(mem.count(it) == 0 || mem[it] == 0) return false;
            else mem[it]--;
        }

        return true;
    }
};
