class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int ans=0;
        for(int i=60;i>=0;i--){
            if(((1LL<<i)&(n))==((1LL<<i)&(m))){
                ans=ans+((1LL<<i)&(n));
            }
            else{
                break;
            }
        }
        return ans;
        
    }
};