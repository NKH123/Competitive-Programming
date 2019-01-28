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

int main()
{   ios::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    ll ans=(n)/(k+1);
    ans=ans*2;
    if(n%(k+1)!=0){

        if(n%(k+1)==1){
            ans=ans+1;
        }
        else{
            ans=ans+2;
        }
    }
    cout<<ans<<"\n";
    return 0;
}