class Solution {
public:
    string shortestPalindrome(string s) {
        if(s=="") return s;
        string r=s, org=s;
        reverse(r.begin(), r.end());
        s= s+"#"+r; //We add "#" here to force the match in reverse(s) starts from its first index and avoid overlapping.
        int n=s.length();
        int lps[n];
        lps[0]=0;
        int len=0;
        for(int i=1; i<n; i++)
        {
            if(s[i]==s[len])
            {
                len++;
                lps[i]=len;
            }
            else
            {
                while(len>0 && s[i]!=s[len]) len=lps[len-1];
                if(len>=0 && s[i]==s[len])
                {
                    len++;
                    lps[i]=len;
                }
                else lps[i]=0;
            }
        }
        for(int i=0;i<n;i++) cout<<lps[i]<<" ";
        return r.substr(0, r.size()-lps[n-1])+org;
    }
};
