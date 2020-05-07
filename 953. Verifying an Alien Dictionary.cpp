class Solution {
public:
    bool isAlienSorted(vector<string>& w, string order) {
        unordered_map<char, int> m;
        for(int i=0;i<order.size();i++) m[order[i]]=i;
        int n=w.size();
        for(int i=0; i<n-1; i++)
        {
            string a=w[i], b=w[i+1];
            int j=0;
            for(j; j<min(a.length(), b.length()); j++)
            {
                if(m[a[j]]<m[b[j]]) break;
                if(m[a[j]]>m[b[j]]) return false;
            }
            if(j==b.length() && j!=a.length()) return false;
        }
        return true;
    }
};
