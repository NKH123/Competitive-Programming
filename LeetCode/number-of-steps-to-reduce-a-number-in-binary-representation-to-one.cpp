class Solution {
public:
    string add(string s){
        string ans;
        ans=s;
        int car=1;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='1' && car==1){
                ans[i]='0';
                car=1;
            }
            else if(s[i]=='1' && car==0){
                ans[i]='1';
            }
            else if(s[i]=='0' && car==0){
                ans[i]='0';
            }
            else if(s[i]=='0' && car==1){
                ans[i]='1';
                car=0;
            }
            
        }
        if(car==1){
            ans="1"+ans;
        }
        return ans;
    }
    
    int numSteps(string s) {
        int st=0;
        while(s!="1"){
            deb(s);
            if(s[s.size()-1]=='0'){
                string ans="";
                for(int i=0;i<s.size()-1;i++){
                    ans+=s[i];
                }
                s=ans;
            }
            else{
                s=add(s);
            }
                 st++;   
        }
        return st;
    }
};