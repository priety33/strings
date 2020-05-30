//consider only alphanumeric chars, therefore skip when !digit && !isalpha
class Solution {
public:
    bool isPalindrome(string s) {
        int i=0, j=s.length()-1;
        while(i<j) {
            while(i<s.length() && !isdigit(s[i]) && !isalpha(s[i])) i++;
            while(j>=0 && !isdigit(s[j]) && !isalpha(s[j])) j--;
            if(i>=j) return true;
            if(tolower(s[i])!=tolower(s[j])) return false;
            i++; j--;
        }
        return true;
    }
};
