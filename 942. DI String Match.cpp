class Solution {
public:
    vector<int> diStringMatch(string S) {
        int n=S.length();
        int i=0, d=n;
        vector<int> ans;
        for(int k=0;k<n;k++)
        {
            if(S[k]=='I')
            {
                ans.push_back(i);
                i++;
            }
            else
            {
                ans.push_back(d);
                d--;
            }
        }
        ans.push_back(i);
        return ans;
    }
};
