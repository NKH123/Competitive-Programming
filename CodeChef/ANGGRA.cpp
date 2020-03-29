#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
#define mod 1000000007

int n, m, k;
int fact[100005];
int power(int a, int b){
    if(b==0){
        return 1LL;
    }
    else{
        int ans=power(a,b/2);
        ans=(ans*ans)%mod;
        if(b%2==1){
            ans=(a*ans)%mod;
        }
        return ans;
    }
}
int nCr(int K){
    int ans=fact[n];
    ans=(ans*power(fact[K],mod-2))%mod;
    ans=(ans*power(fact[n-K],mod-2))%mod;
    return ans;
}
int fun(int K){
    int ans=1;
    ans=nCr(K);
    ans=(ans*power(m-1,K))%mod;
    return ans;
}

int32_t main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    fact[0]=1;
    for(int i=1;i<100005;i++){
        fact[i]=(i*fact[i-1])%mod;
    }
    while(t--){
        cin>>n>>m>>k;
        int ans=0;
        for(int i=k;i<=n;i++){
            ans=(ans+fun(n-i))%mod;
        }
        cout<<ans<<"\n";
    }
    return 0;
}