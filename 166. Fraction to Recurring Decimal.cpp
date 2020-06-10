class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
         
         if(numerator == 0 || denominator == 0)
         {
             return "0";
         }
         string s = "";
         unordered_map<long,long> mp;
        
         if((numerator<0) ^ (denominator<0)){
              s='-';
         }
         long n = abs((long)numerator);
         long d = abs((long)denominator);
        
         s+= to_string(n/d);
         long rem = n%d;
         
         if(!rem){ return s; }
         
         s += '.';
        
         rem *= 10;
         
         while(rem){
                if(mp.find(rem)!=mp.end())
                {
                     s.insert(mp[rem],1,'(');
                     s+=')';
                     break;
                }
             mp[rem] = s.size();
             s += to_string(rem/d);
             rem = (rem%d)*10;
         } 
        
    return s;
    }
    
};
