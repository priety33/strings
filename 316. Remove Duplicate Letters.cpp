//lexigraphically smallest subsequence containing all characters
/*
Find the index of last occurrence for each character.
Use a stack to keep the characters for result.
Loop on each character in the input string S,
if the current character is smaller than the last character in the stack,
and the last character exists in the following stream,
we can pop the last character to get a smaller result.
*/
class Solution {
public:
       string removeDuplicateLetters(string s) {
        string res = "";
        int last[26] = {}, seen[26] = {}, n = s.size();
        for (int i = 0; i < n; ++i)
            last[s[i] - 'a'] = i;
        for (int i = 0; i < n; ++i) {
            if (seen[s[i] - 'a']++) continue;
            while (!res.empty() && res.back() > s[i] && i < last[res.back() - 'a'])
                seen[res.back() - 'a'] = 0, res.pop_back();
            res.push_back(s[i]);
        }
        return res;
    }
};
