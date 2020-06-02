//backtracking
class Solution {
public:
    string ans="";
    
    void gen(int n, int &k, int len, char last_char) {
        if(len==n) {
            k--;
            return;
        }
        for(char ch='a'; ch<='c'; ch++) {
            if(ch!=last_char) {
                ans+=ch;
                gen(n, k, len+1, ch);
                if(k==0) return;
                ans.pop_back();
            }
        }
    }
    
    string getHappyString(int n, int k) {
        gen(n, k, 0, 0);
        return ans;
    }
};
