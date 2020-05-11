class Solution {
public:
    string pushDominoes(string d) {
        int n=d.length();
        
        string ls=d;
        int l=n-1;
        bool left=false;
        while(l>=0)
        {
            if(d[l]=='R') left=false;
            else if(d[l]=='.' && left) ls[l]='L';
            else if(d[l]=='L') left=true;
            l--;
        }
        
        string rs=d;
        int r=0;
        bool right=false;
        while(r<n)
        {
            if(d[r]=='L') right=false;
            else if(d[r]=='.' && right) rs[r]='R';
            else if(d[r]=='R') right=true;
            r++;
        }
        
        for(int s=0; s<n; s++)
        {
            if(ls[s]==rs[s]) continue;
            else if(ls[s]=='L' && rs[s]=='.') d[s]='L';
            else if(rs[s]=='R' && ls[s]=='.') d[s]='R';
            else
            {
                int e=s+1;
                while(e<n && rs[e]=='R') e++;
                e--;
                int end=e;
                while(s<e)
                {
                    d[s]='R'; d[e]='L';
                    s++; e--;
                }
                if(s==e) d[s]='.';
                s=end;
            }
        }
        return d;
    }
};
