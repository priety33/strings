class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> m;
        vector<vector<int>> ret;
        for (int i = 0; i < words.size(); i++) m[words[i]] = i;
        for (int i = 0; i < words.size(); i++)
        {
            string rev = words[i];
            reverse(rev.begin(), rev.end());
            if (m.find(rev) != m.end() && i != m[rev]) ret.push_back({i, m[rev]});
            for (int k = 1; k <= words[i].length(); k++) //k=lemgth of palindromic part
            {
                if (isP(rev, 0, k) == true) //if left part is already palindrome
                {
                    auto it = m.find(rev.substr(k));
                    if (it != m.end() && i != it->second) ret.push_back({i, it->second});
                }
                if (isP(rev, rev.length() - k, k) == true) //if right part is already palindrome
                {
                    auto it = m.find(rev.substr(0, rev.length() - k));
                    if (it != m.end() && i != it->second) ret.push_back({it->second, i});
                }
            }
        }
        return ret;
    }
    bool isP(string& s, int start, int len) //is substring a palindrome
    {
        for (int i = start; i < start + len / 2; i++) if (s[i] != s[2 * start + len - 1 - i]) return false;
        return true;
    }
};
