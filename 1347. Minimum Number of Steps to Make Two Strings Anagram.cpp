class Solution {
public:
    int minSteps(string s, string t) {
        int count=0;
        unordered_map<char,int> mt, ms;
        for(int i=0;i<s.length();i++)
        {
            ms[s[i]]++;
            mt[t[i]]++;
        }
        for(auto it: mt)
        {
            int a=it.second;
            if(ms.find(it.first)!=ms.end()) a-=ms[it.first];
            if(a>0) count+=a;
        }
        return count;
    }
};
