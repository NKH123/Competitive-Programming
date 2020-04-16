class Solution {
public:
    bool checkValidString(string s) {
        int hi=0, lo=0;
        for(auto g:s){
            if(g=='('){
                lo=lo+1;
                hi=hi+1;   
            }
             if(g==')'){
                hi=hi-1;
                lo=lo-1;
            }
            if(g=='*'){
                lo=lo-1;
                hi=hi+1;
            }
            lo=max(0,lo);
            if(hi<0){
                return false;
            }
        }
        return (lo<=0 && 0<=hi);
        
        
    }
};