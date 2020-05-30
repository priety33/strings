class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<string, int> m;
        int len=0, i=0, j=0, n=s.length();
        while(i<n && j<n) {
            if(m.find(s.substr(j,1))!=m.end() && i<=m[s.substr(j,1)]) i= m[s.substr(j,1)]+1;
            m[s.substr(j,1)]=j;
            cout<<i<<" "<<j<<endl;
            if(i<=j) len=max(len, j-i+1);
            j++;
        }
        return len;
    }
};
