#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <b; i++)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define llp 1000000007
int t;
ll n,m;
vector<long long> a;
vector<long long> b;

int main()
{   ios::sync_with_stdio(false);
    cin>>t;
    ll fib[100005];
    fib[1]=1;
    fib[2]=1;
    REP(i,3,100001){
        fib[i]=(fib[i-1]%llp+fib[i-2]%llp)%llp;
    }
    while(t--){
        cin>>m>>n;
        a.clear();
        b.clear();
        b.resize(m);
        a.resize(m);
        ll asum=0;
        ll bsum=0;
        REP(i,0,m){
            cin>>a[i];
            asum=(asum+a[i])%llp;
        }
        REP(i,0,m){
            cin>>b[i];
            bsum=(bsum+b[i])%llp;
        }
       if(n==1){
           cout<<((m)*(suma%llp))%llp<<"\n";
       }
       else if(n==2){
           cout<<(m*(sumb%llp))%llp<<"\n";
       }
       else{
           cout<<(m*((fib[n-2]*(suma%llp)+fib[n-1]*(sumb%llp))%llp))%llp<<'\n';
       }


    }
    return 0;
}