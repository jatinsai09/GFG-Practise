/*complete the Function*/

class Solution {
    public:
    bool isValid(string &s){
        int n=s.size();
        if(n==1){
            return true;
        }
        
        int val=stoi(s);
        if(s[0]=='0' || val>255){
            return false;
        }
        return true;
    }
    
    void generateIpRec(string& s,int i,string cur,int cnt,vector<string>& res){
        string temp="";
        if(i>=s.size()){
            return;
        }
        
        if(cnt==3){
            temp=s.substr(i);
            if(temp.size()<=3 && isValid(temp)){
                res.push_back(cur+temp);
            }
            return;
        }
        
        for(int j=i;j<min(i+3,(int)s.size());j++){
            temp+=s[j];
            
            if(isValid(temp)){
                generateIpRec(s,j+1,cur+temp+'.',cnt+1,res);
            }
        }
    }
    vector<string> generateIp(string s) {
        // code here
        vector<string> res;
        generateIpRec(s,0,"",0,res);
        return res;
    }
};
