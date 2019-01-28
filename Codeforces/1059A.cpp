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
int n,L,a;
int main()
{   ios::sync_with_stdio(false);
    cin>>n>>L>>a;
    int t,l;
    int cur=0;
    int ans=0;
    REP(i,0,n){
        cin>>t>>l;
        int diff=t-cur;
        if(diff>=a){
            int ct=diff/a;
            ans+=ct;
             //cout<<"I'm here0\n";
        }
        cur=t+l;
    }
    if(cur<L){
        int diff=L-cur;
        if(diff>=a){
            int ct=diff/a;
            ans+=ct;
            //cout<<"I'm here1\n";
        }
    }
    cout<<ans<<"\n";
    return 0;
}