class Solution {
public:
    string orderlyQueue(string S, int K) {
        if(K>1) 
        {
           sort(S.begin(), S.end());
           return S;
        }
        else
        {
            string ans=S;
            for(int i=0; i<S.length(); i++)
            {
                string T= S.substr(i)+S.substr(0,i);
                if(T < ans) ans= T;
            }
            return ans;
        }
        return S;
    }
};
