//O(nlogn)- using sort
class Solution {
public:
    
    static bool compare( pair<int,string> a, pair<int,string> b ) {
        return a.first>b.first;
    }
    
    string frequencySort(string s) {
        string ans="";
        vector<pair<int,string>> v(256, make_pair(0,""));
        for(int i=0; i<s.length(); i++) {
            v[s[i]-' '].first++; // space is the first char in ASCII
            v[s[i]-' '].second+= s.substr(i,1);
        }
        sort(v.begin(), v.end(), compare);
        for(int i=0; i<v.size() && v[i].second!=""; i++) ans+=v[i].second; 
        return ans;
    }
};


//O(n)
class Solution {
public:
    
    string frequencySort(string s) {
        string ans="";
        int n=s.size();
        unordered_map<string,int> m;
        vector<string> v(n+1, "");
        for(int i=0; i<s.size(); i++) m[s.substr(i,1)]++;
        for(auto i: m)
        {
            int x=i.second;
            while(i.second--) v[x]+=i.first;
        }
        for(int i=n; i>0; i--) if(v[i]!="") ans+=v[i];
        return ans;
    }
};
