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
ll a,b,x,y;
ll GCD(ll a, ll b){
    if(b==0){
        return a;
    }
    else{
        return GCD(b,a%b);
    }
}
int main()
{   ios::sync_with_stdio(false);
    cin>>a>>b>>x>>y;
    while(GCD(x,y)!=1){
        ll X=x;
        ll Y=y;
        x=x/GCD(X,Y);
        y=y/GCD(X,Y);
    }
    //cout<<"a="<<a<<"b="<<b<<"x="<<x<<"y="<<y<<"\n";
    cout<<min(a/x,b/y)<<"\n";


    return 0;
}