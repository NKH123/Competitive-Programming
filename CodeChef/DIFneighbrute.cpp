#include <bits/stdc++.h>
using namespace std;
#define ll long long 


ll a[50][50];
ll cnt=0;

bool left(ll i,ll j,ll m,ll n,ll l){
    if(i && j){
        if(a[i-1][j-1]==l) return false;

    }
    return true;
}
bool above(ll i,ll j,ll m,ll n,ll l){
    if(i>1){
        if(a[i-2][j]==l){
            return false;
        }
    }
    return true;
}
bool lh(ll i,ll j,ll m,ll n,ll l){
    if(j>1){
        if(a[i][j-2]==l){
            return false;
        }
    }
    return true;
}

bool ur(ll i,ll j,ll m,ll n,ll l){
    if(i && j<n-1){
        if(a[i-1][j+1]==l){
            return false;
        }
    }    
    return true;
}


bool can_ans(ll m,ll n,ll i,ll j,ll k){
    if(i==m){
        if(k==3)
        cout<<m<<" "<<n<<"-->"<<k<<endl;
        cnt=1;
        return true;
    }
    if(m==1 && n==1){
        //cout<<m<<" "<<n<<"-->"<<k<<endl;
        return true;
    }
    if(j==n){
        return can_ans(m,n,i+1,0,k);
    }
    bool ans=false;
    for(ll l=1;l<=k;l++){
        bool check=( above(i,j,m,n, l) && ur( i, j, m, n, l) && lh( i, j, m, n, l) && left( i, j, m, n, l) );
        if(!check){
            continue;
        }
        a[i][j]=l;
        ans=(ans||can_ans(m,n,i,j+1,k));
        break;
    }
    
    return ans;
}


int main() {

    ll t;
    cin>>t;
    
    while(t--){
        ll m,n;
        cin>>m>>n;
        memset(a,-1,sizeof(a));
        ll si=1,ei=4;
        ll ans=-1;  
        
        while(si<=ei){
            if(can_ans(m,n,0,0,si)){
                ans=si;
                break;
            }
            si++;
        }
        cnt=0;
    }
    
    for(ll i=1;i<=50;i++){
        for(ll j=1;j<=50;j++){
            for(ll k=1;k<=4;k++){
                bool s=can_ans(i,j,0,0,k);
                if(s) break;
            }
        }
    }

}
