#include<bits/stdc++.h>
#define int long long
using namespace std;

vector<int> r;
vector<int> g;
vector<int> b;
int ans=4*(1e18);
int getans(vector<int> A, vector<int> B, vector<int> C){
    int X, Y, Z;
    X=A[0];
    Y=B[0];
    Z=C[0];
    ans=min(ans,(X-Y)*(X-Y)+(Y-Z)*(Y-Z)+(X-Z)*(X-Z));
    vector<int>ll(3);
    vector<int>rr(3);
    for(int i=0;i<B.size();i++){
        ll[0]=-1, ll[1]=-1, ll[2]=-1;
         rr[0]=-1, rr[1]=-1, rr[2]=-1;
        ll[0]=lower_bound(A.begin(),A.end(),B[i])-A.begin();
        if(ll[0]==A.size()){
            ll[0]--;
        }
        if(ll[0]==0){
            if(A[0]>B[i]){
                ll[0]=-1;
            }
        }
        else{
            ll[0]--;
        }
        ll[1]=lower_bound(A.begin(),A.end(),B[i])-A.begin();
        if(ll[1]==A.size()){
            ll[1]--;
        }
        ll[2]=upper_bound(A.begin(),A.end(),B[i])-A.begin();
        if(ll[2]==A.size()){
            ll[2]--;
        }
        rr[0]=lower_bound(C.begin(),C.end(),B[i])-C.begin();
        if(rr[0]==C.size()){
            rr[0]--;
        }
        if(rr[0]==0){
            if(C[0]>B[i]){
                rr[0]=-1;
            }
        }
        else{
            rr[0]--;
        }
        rr[1]=lower_bound(C.begin(),C.end(),B[i])-C.begin();
        if(rr[1]==C.size()){
            rr[1]--;
        }
        rr[2]=upper_bound(C.begin(),C.end(),B[i])-C.begin();
        if(rr[2]==C.size()){
            rr[2]--;
        }
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                if(ll[j]!=-1 && rr[k]!=-1){
                    X=A[ll[j]];
                    Y=B[i];
                    Z=C[rr[k]];
                    ans=min(ans,(X-Y)*(X-Y)+(Y-Z)*(Y-Z)+(X-Z)*(X-Z));
                }
            }
        }
    }
    return ans;
}

int32_t main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        ans=4*(1e18);
        int nr, ng, nb;
        cin>>nr>>ng>>nb;
        r.clear();
        r.resize(nr);
        g.clear();
        g.resize(ng);
        b.clear();
        b.resize(nb);
        for(int i=0;i<nr;i++){
            cin>>r[i];
        }
        for(int i=0;i<ng;i++){
            cin>>g[i];
        }
        for(int i=0;i<nb;i++){
            cin>>b[i];
        }
        sort(r.begin(),r.end());
        sort(g.begin(),g.end());
        sort(b.begin(),b.end());
        int ans=getans(r,g,b);
        ans=min(ans,getans(g,r,b));
        ans=min(ans,getans(g,b,r));
        cout<<ans<<"\n";
    }


    return 0;
}