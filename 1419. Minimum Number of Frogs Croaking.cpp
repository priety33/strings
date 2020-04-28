class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int num[5] = {} , frog = 0, max_frog=0;
        for (int i = 0 ; i < croakOfFrogs.size() ; ++ i) {
            if (croakOfFrogs[i] == 'c') {
                ++num[0];
                frog++;
                max_frog=max(frog, max_frog);
            }
            if (croakOfFrogs[i] == 'r') {
                if (!num[0]) return -1;
                -- num[0];
                ++ num[1];
            }
            if (croakOfFrogs[i] == 'o') {
                if (!num[1]) return -1;
                -- num[1];
                ++ num[2];
            }
            if (croakOfFrogs[i] == 'a') {
                if (!num[2]) return -1;
                -- num[2];
                ++ num[3];
            }
            if (croakOfFrogs[i] == 'k') {
                if (!num[3]) return -1;
                -- num[3];
                frog--;
            }
        }
        if (num[0] || num[1] || num[2] || num[3]) return -1;
        return max_frog;
    }
};
