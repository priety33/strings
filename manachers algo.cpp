class Solution {
public:
    string longestPalindrome(string s) {
        string p="#";
        for(int i=0;i<s.length();i++) p+=s.substr(i,1)+"#";
        int n=p.length();
        vector<int> m(n, 0);
        
        int c=0, r=0, len=0, centre=0;
        for(int i=0; i<n; i++)
        {
            int mir= 2*c-i;
            
            //in boundary?
            if(i<r) m[i]=min(r-i, m[mir]);
            
            //outside boundary-> check using brute force, i as centre.
            while(i+m[i]+1<n && i-m[i]-1>=0 && p[i+m[i]+1]==p[i-m[i]-1]) m[i]++;
            
            //update boundary if r is increased
            if(i+m[i]>r)
            {
                c=i;
                r=i+m[i];
            }
            
            //calculate max len found uptill here
            if(len<m[i])
            {
                len=m[i];
                centre=i;
            }
        }
        string ans="";
        for(int i=centre-len; i<=centre+len; i++) if(p[i]!='#') ans+=p[i];
        return ans;
    }
};
