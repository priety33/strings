class Solution {
public:
    
vector<string> maxNumOfSubstrings(string s) {
        int n=s.length();
        vector<int> last_occurance(26,-1);//notes the last occurance of every character from a to z
        for(int i=n-1;i>=0;i--){
            if(last_occurance[s[i]-'a']==-1)
                last_occurance[s[i]-'a']=i;
        }
        
        unordered_set<char> done;//keeps track of used alphabets
        vector<pair<int,int>> interval;//keeps the indices of an interval satisfying condition 2
        
        for(int i=0;i<n;i++){
            int range=i;
            bool flag=true;
            for(int j=i;j<=range;j++){
                if(done.count(s[j])){//s[j] has already been encoutered before, thus this interval cannot take all occurances of s[j]
                    flag=false;
                    break;
                }
                range=max(range,last_occurance[s[j]-'a']);
            }
            if(flag)
                interval.push_back({i,range}); //beacuse i is sorted, starting from 0, start of intervals will be sorted
            done.insert(s[i]);
        }
        
        //maximum non overlapping interval
        int temp=0;
        vector<string> result;
        for(int i=1;i<interval.size();i++){
            if(interval[i].first>interval[temp].second){
                result.push_back(s.substr(interval[temp].first,interval[temp].second-interval[temp].first+1));
                temp=i;
            }
            else{
                if(interval[i].second<=interval[temp].second){//i is a better string than temp since it is shorter-> start[i]>temp and end[i]<temp                               
                    temp=i;
                }
            }
        }
        result.push_back(s.substr(interval[temp].first,interval[temp].second-interval[temp].first+1));
        return result;
   }
};
