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
int n;
vi a;

int main()
{   ios::sync_with_stdio(false);
    cin>>n;
    ll x,f;
    a.resize(n);
    REP(i,0,n){
        cin>>a[i];
        //cout<<"i="<<i<<"\n";
    }
    ll ans=0;
    cin>>x>>f;
    //cout<<"I'm here\n";
    for(int i=0; i<n; i++){
        if(a[i]>x){
            int rem=a[i]-x;
            int count=rem/(x+f);
            //count++;
            if(a[i]%(x+f)>x){
                count++;
            }
            ans+=f*count;
        }
    }
    cout<<ans<<"\n";
    return 0;
}