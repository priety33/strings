class Solution {
public:
    
    void leftshift(string &s, int a)
    {
        if(a==0) return;
        s+=s[0];
        s.erase(0,1);
        leftshift(s, a-1);
    }
    
    void rightshift(string &s, int a)
    {
        if(a==0) return;
        s=s[s.size()-1]+s;
        s.erase(s.size()-1, 1);
        rightshift(s, a-1);
    }
    
    string stringShift(string s, vector<vector<int>>& shift) {
        if(shift.size()==0) return s;
        int n=shift.size();
        for(int i=0; i<n; i++)
        {
            if(shift[i][0]==0) leftshift(s, shift[i][1]);
            else rightshift(s, shift[i][1]);
        }
        return s;
    }
};
