class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i=0, j=0;
        while(i<name.length() && j<typed.length()) {
            if(name[i]==typed[j]) {
                i++; j++;
            }
            else if(j && typed[j]==typed[j-1]) j++;
            else return false;
        }
        while(j<typed.length() && typed[j]==typed[j-1]) j++;
        return i==name.length() && j==typed.length();
    }
};
