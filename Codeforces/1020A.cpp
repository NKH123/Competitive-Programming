#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define REP(i,a,b) for (int i = a; i <b; i++)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define llp 1000000007
ll n,h,a,b;
int k;
ll A,B,C,D;

int main()
{   ios::sync_with_stdio(false);
    cin>>n>>h>>a>>b>>k;

    while(k--){
        cin>>A>>B>>C>>D;
        if(A==C){
            cout<<abs(B-D)<<"\n";
        }
        else{
            ll add=0;
            ll BN=B;
            if(B>b || B<a){
                if(B>b){
                    add=abs(B-b);
                    BN=b;
                }
                else{
                    add=abs(B-a);
                    BN=a;
                }
            }
            /*else{


            }*/
            ll ans=add+abs(A-C);
            ans=ans+abs(BN-D);
            cout<<ans<<"\n";
        }
    }
    return 0;
}