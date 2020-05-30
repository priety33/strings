class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(k>s.length()) return false;
        unordered_map<string, int> sub, m;
        for(int i=0; i<=s.length()-k; i++) sub[s.substr(i,k)]=1;
        return sub.size()==pow(2,k);
    }
};
