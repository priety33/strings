class Solution {
public:
    
    bool isprefix(string s, string p) {
        bool prefix=false;
        int k=0,j=0;
        for(j ; j<s.length() && k<p.length(); j++, k++) {
            if(s[j]!=p[k]) break;
        }
        if(k==p.length()) return true;
        return false;
    }
    
    int isPrefixOfWord(string s, string p) {
        int i=0, w=1;
        while(i<s.length()) {
            int j=i;
            while(j<s.length() && s[j]!=' ') j++;
            if(isprefix(s.substr(i,j-i), p)) return w;
            i=j+1; w++;
        }
        return -1;
    }
};
