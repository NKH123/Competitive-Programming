class Solution {
public:
    int no_digits(int n){
        int ans=0;
        while(n>0){
            n=n/10;
            ans++;
        }
        return ans;
    }
    int process(int n){
        int ans=0;
        while(n>0){
            int N=n%10;
            ans=ans+N*N;
            n=n/10;
        }
        return ans;
    }
    bool isHappy(int n) {
        int iter=0;
        while(n!=1){
                n=process(n);
                iter++;
            if(iter>100000){
                break;
            }
        }
        return n==1;
    }
};