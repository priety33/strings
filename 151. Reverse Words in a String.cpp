class Solution {
public:
    string reverseWords(string &s) {
        int start = 0;
        int i = 0;
        while( s[i] == ' ') s.erase(i, 1);
        
        reverse(s.begin(), s.end());
        
        while( s[i] == ' ') s.erase(i, 1);

        int size = s.size();
        for(i = 0; i < size - 1; i++){
            if( s[i] == ' '){
                if( i == start ){
                    s.erase(i--,1);
                    size--;
                }
                else{
                    reverse(s.begin()+start, s.begin()+i);
                    start = i+1;
                }
            }
        }
        //reverse last word, when i==size.
        reverse(s.begin() + start, s.end());
        return s;
    }
};
