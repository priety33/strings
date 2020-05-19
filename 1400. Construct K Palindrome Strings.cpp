class Solution {
public:
    bool canConstruct(string s, int k) {
        if(k>s.size()) return false;
        unordered_map< char, int> m;
        for(int i=0; i<s.size(); i++) m[s[i]]++;
        int even=0, odd=0;
        for(auto i: m)
        {
            if(i.second%2) odd++;
            else even++;
        }
        if(odd>k) return false;
        return true;
    }
};
