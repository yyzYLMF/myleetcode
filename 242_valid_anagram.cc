class Solution {
    public:
        bool isAnagram(string s, string t) {
            map<char,int> sign;
            int i,lens,lent;
            lens = s.size();
            lent = t.size();
            if(lens != lent)
                return false;
            if(lens == 0)
                return true;
            for(i=0; i<lens; ++i) {
                sign[s[i]]++;
            }
            for(i=0; i<lent; ++i) {
                if(sign[t[i]] > 0)
                    sign[t[i]]--;
                else
                    break;
            }
            if(i != lent)
                return false;
            else
                return true;
        }
};
