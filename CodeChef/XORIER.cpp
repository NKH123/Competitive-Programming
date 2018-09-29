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
int n;
vi a;
int main()
{   ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        cin>>n;
        a.clear();
        a.resize(n);
        ll odd=0;
        ll eve=0;
        unordered_map<ll,ll > m;
        m.clear();
        REP(i,0,n){
            cin>>a[i];
            m[a[i]]++;
            if(a[i]%2){
                odd++;
            }
            else{
                eve++;
            }
        }
        ll ans=odd*(odd-1)+eve*(eve-1);
         ans=ans/2;
         //cout<<"ans="<<ans<<"\n";
        unordered_map<ll, ll> M(m);
        REP(i,0,n){
            if(m[a[i]]>1){
                ll diff=m[a[i]]*(m[a[i]]-1)/2;
                ans=ans-diff;
                m[a[i]]=1;
            }

            if(M.find(a[i]^2)!=M.end()){
                ans=ans-M[a[i]^2];
                M.erase(a[i]);
            }
        }
        cout<<ans<<"\n";



    }
    return 0;
}
