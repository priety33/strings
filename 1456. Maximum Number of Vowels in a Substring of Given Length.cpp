class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_set<char> vowel;
        vowel.insert('a');
        vowel.insert('e');
        vowel.insert('i');
        vowel.insert('o');
        vowel.insert('u');
        int l=0,e=0,count=0, ans=0;
        while(e<s.length() && e<k) {
            if(vowel.find(s[e])!=vowel.end()) count++;
            e++;
        }
        e--;
        ans=count;
        while(e<s.length()) {
            if(vowel.find(s[l])!=vowel.end()) count--;
            l++;
            e++;
            if(e<s.length() && vowel.find(s[e])!=vowel.end()) count++;
            ans=max(ans, count);
        }
        return ans;
    }
