class Solution {
public:
int compareVersion(string version1, string version2) {

    int i=0, j=0;
    int len1 = version1.length();
    int len2 = version2.length();
    
    while(i<len1 || j<len2) 
    {
        int M = 0;
        int N = 0;
        string s1 = "";
        string s2 = "";
        
        while(i<len1 && version1[i] != '.') 
        {
            s1 += version1[i];
            i++;
        }
        
        while(j<len2 && version2[j] != '.') 
        {
            s2 += version2[j];
            j++;
        }
        
        if(s1.length() > 0)
            M = stoi(s1);
        
        if(s2.length() > 0)
            N = stoi(s2);
        
        if(M > N) return 1;
        else if(M < N) return -1;
        
        i++; j++;
    }
    
    return 0;
}
};
