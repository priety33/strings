class Solution {
public:
    string reformat(string s) {
        int k=s.length();
        string ch="", nu="";
        for(int i=0;i<k;i++)
        {
            if(s[i]>='0' && s[i]<='9') nu+=s[i];
            else ch+=s[i];
        }
        if(ch.length()>nu.length()) swap(ch, nu);
        if(ch.length()+1<nu.length()) return "";
        string ans="";
        ans+=nu[0];
        for(int c=0, n=1; c<ch.size(); c++,n++)
        {
            ans+=ch[c];
            ans+=nu[n];
        }
        return ans;
    }
};
