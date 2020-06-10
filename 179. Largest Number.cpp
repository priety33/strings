class Solution {
public:
    
    static bool compare(int a, int b) {
        if(a==b) return a<b;
        string x= to_string(a), y=to_string(b);
        if(x+y>y+x) return true;
        return false;
    }
    
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), compare);
        string ans="";
        for(auto i: nums) ans+=to_string(i);
        if(ans[0]=='0') return "0";
        return ans;
    }
};
