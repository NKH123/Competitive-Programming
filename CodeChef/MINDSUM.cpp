#include<bits/stdc++.h>
using namespace std;
long long ans=1L<<60;
int moves=0;
long long getSum(long long N){
    long long ret=0;
    while(N!=0){
        ret=ret+N%10;
        N=N/10;
    }
    return ret;
}
void Reduce(long long N){
    while(N/10 !=0){
        N=getSum(N);
        moves++;
    }
    ans=min(N,ans);
}
int main(){
    cout<<getSum(9876);
    int t;
    cin>>t;
    long long n,d;
    while(t--){
        int M=0;
        int moves=0;
    ans=1L<<60;
    cin>>n>>d;
    for(int i=0;i<=9;i++){
        long long Ans=ans;
        moves=i;
        Reduce(n+i*d);
        if(Ans>ans){
            M=moves;
        }
        else if(Ans==ans){
            M=min(M,moves);
        }
    }
    cout<<ans<<" "<<M<<"\n";
    }
    return 0;
}