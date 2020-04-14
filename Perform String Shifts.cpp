class Solution {
public:
    string stringShift(string str, vector<vector<int>>& shift) {
        int s=0;
        for(int i=0;i<shift.size();i++){
            if(shift[i][0]==0)s-=shift[i][1]; //left shift
            else s+=shift[i][1]; //right shift
        }
        cout << s <<endl;
        if(s<0){
            s=-1*s;
            s=s%str.size();
            str=str.substr(s,str.size()-s)+str.substr(0,s);
            return str;
        }
        s=s%str.size();
        if(s==0) return str;
        str=str.substr(str.size()-s,s)+str.substr(0,str.size()-s);
        return str;
    }
};
