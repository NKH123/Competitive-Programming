#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define ld long double
#define pp pair<ll,ll>
const ll mod = 1e9+7;
ll n;
vector<pp> v;

map<pp,ld> dp;
map<ll,vector<ll>> m;

ld find_dist(pp a,pp b){
    ld ans=0;
    ans=(a.first-b.first);
    ans*=ans;
    ld ans1=(a.second-b.second);
    ans1*=ans1;
    return ans+ans1;
}

ld dist(ll a,ll b,ll c,ll d){
    ld ans=0;
    ans+=(find_dist(m[a][b],m[c][d]));
    return ans;
}

ld f(ll pos,ll j){
    if(pos==n){
        return 0;
    }
    if(dp.count(make_pair(pos,j))){
        return dp[make_pair(pos,j)];
    }
    ld ans=0;
    for(ll k=0;k<4;k++){
        ans=min(ans,f(pos+1,k)+dist(pos,j,pos+1,k)+4*v[pos].first);
    }
    return ans;
}

int main()
{
    
    
    ll tt;
    cin>>tt;
    while(tt--){
        
        cin>>n;
        v.clear();
        
        for(ll i=0;i<n;i++){
            cin>>v[i].first;
        }    
        v[0].second=0;
        for(ll i=0;i<n-1;i++){
            ll d;
            cin>>d;
            v[i+1].second=v[i].first+v[i].second+d;
        }
        m.clear();
        
        m[0].push_back(make_pair(0,0));
        m[0].push_back(make_pair(0,v[0].first));
        m[0].push_back(make_pair(v[0].first,v[0].first));
        m[0].push_back(make_pair(v[0].first,0));
        for(ll i=1;i<n;i++){
            m[i].push_back(make_pair(v[i].second,0));
            m[i].push_back(make_pair(v[i].second,v[i].first));
            m[i].push_back(make_pair(v[i].second+v[i].first,v[i].first));
            m[i].push_back(make_pair(v[i].second+v[i].first,0));
        }
        dp.clear();
        ld ans=0;
        ans=f(0,0);
        cout<<ans<<endl;        
        
    }
    
    return 0;
}
