#include <bits/stdc++.h>
using namespace std;
#define int long long 

const int mod = 1e9+9;


int power(int a,int b){
    if(b==0)return 1;
    int s=power(a,b/2);
    s*=s;
    s%=mod;
    if(b&1)return (s*a)%mod;
    return s;
}

int inv(int a){
    return power(a,mod-2);
}

signed main()
{
    
    int n;
    int a,b,k;
    cin>>n>>a>>b>>k;
    int sum=0;
    string s;
    cin>>s;
    int mod1=mod-1;
    for(int i=0;i<k;i++){
        int b=-1;
        if(s[i]=='+')b=1;
        sum+=(b*power(a,n-i)*power(b,i))%mod;
        sum%=mod;
        sum=(sum+mod)%mod;
    }
    
    int ans=1;
    ans=power(a,n+1)-power(b,n+1);
    ans=(ans%mod+mod)%mod;
    ans*=inv(((power(a,k)-power(b,k))%mod+mod)%mod);
    ans%=mod;
    ans*=inv(power(a,n+1-k));
    ans%=mod;
    ans*=sum;
    ans=(ans%mod+mod)%mod;
    cout<<ans<<endl;
    
    return 0;
}
