class Solution {
public:
    string decodeAtIndex(string s, int K) {
        long long len=0;
        for(int i=0;i<s.length();i++)
        {
            if(isdigit(s[i])) len*=s[i]-'0';
            else len++;
        }
        cout<<len;
        for(int i=s.length()-1; i>=0; i--)
        {
            K=K%len;
            if(K==0 && isalpha(s[i])) return s.substr(i,1);
            
            if(isdigit(s[i])) len=len/(s[i]-'0');
            else len--;
        }
        return "";
    }
};
