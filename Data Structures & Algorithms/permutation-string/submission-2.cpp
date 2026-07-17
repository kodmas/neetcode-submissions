class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) return false;
        map<char, int> mem;

        for(auto c:s1){
            if(!mem.count(c)) mem.insert({c,1});
            else mem[c]++;
        } 
        int i = 0;
        int j = i;
        map<char, int> cur = mem;
        // bool flag = false;
        // int counter = 0;
        while(i <= s2.length()-s1.length()){
            // counter++;
            // cout << s1 <<counter << endl;
            while(j < i+s1.length()){
                // counter++;
                // cout << counter << endl;
                // if(counter > 100) break;
                // cout << i << " " << j << endl;
                if(!cur.count(s2[j]) || cur[s2[j]] == 0){
                    // cout << "r1" << endl;
                    cur = mem;
                    i = i+1;
                    j = i;
                    break;
                }
                else{
                    // cout << "r2" << endl;
                    cur[s2[j]]--;
                    if(j == i+s1.length()-1){
                        // cout << "t" << endl;
                        // flag = true;
                        // break;
                        return true;
                    }
                }
                j++;
            }
            // if(flag) return true;
            // if(counter > 100) break;
        }

        return false;
            
    }
};
