#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <b; i++)
typedef long long ll;
#define int ll
typedef vector<int> vi;
typedef vector<long long> vl;
typedef pair<int,int> pi;
#define trace(x) cout<<#x<<"="<<x<<"\n";
#define sz(x) (int)(x.size())
#define mod 1000000007
#define endl "\n"


vector<vector<int> >ct;
int32_t main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    vi a;
    while(t--){
        int n;
        cin>>n;
        a.clear();
        a.resize(n);
        ct.clear();
        ct.resize(27,vector<int>(n,0));
        a.clear();
        a.resize(n);
        REP(i,0,n){
            cin>>a[i];
            ct[a[i]][i]=1;
        }
        int ll=0;
        for(int i=1;i<=26;i++){
            for(int j=0;j<n;j++){
                if(j==0){

                }
                else{
                    ct[i][j]+=ct[i][j-1];
                }
            }
        }
        int ans=0;
        int rr=0;
        int mM=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                ll=0, rr=0, mM=0;
                int mm=0;
                for(int I=1;i<=26;I++){
                    // LR=max(LR,ct[i-1][I])

                    if(i!=0){
                        ll=ct[I][i-1];
                    }

                    if(j!=(n-1)){
                        // rr=ct[I][j+1]-ct[I][i-1];
                        if(i==0){
                            rr=ct[I][n-1];
                        }
                        else{
                            rr=ct[I][n-1]-ct[I][j];
                        }
                    }
                    else{
                        if(i==0){
                            rr=ct[I][n-1];
                        }
                        else{
                            rr=ct[I][n-1]-ct[I][j];
                        }
                    }

                    mm=ct[I][j];
                    if(i!=0){
                        mm-=ct[I][i-1];
                    }
                    mM=max(mM,mm);

                }
                ans=max(ans,2*(min(ll,rr))+mM);
            }
        }
        cout<<ans<<"\n";


    }

    return 0;
}