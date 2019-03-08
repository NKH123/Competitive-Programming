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
#define llp 1000000007
#define mod 1000000007

template < typename F, typename S >
ostream& operator << ( ostream& os, const pair< F, S > & p ) {
    return os << "(" << p.first << ", " << p.second << ")";
}

template < typename T >
ostream &operator << ( ostream & os, const vector< T > &v ) {
    os << "{";
    typename vector< T > :: const_iterator it;
    for( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << *it;
    }
    return os << "}";
}

template < typename T >
ostream &operator << ( ostream & os, const set< T > &v ) {
    os << "[";
    typename set< T > :: const_iterator it;
    for ( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << *it;
    }
    return os << "]";
}

template < typename F, typename S >
ostream &operator << ( ostream & os, const map< F, S > &v ) {
    os << "[";
    typename map< F , S >::const_iterator it;
    for( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << it -> first << " = " << it -> second ;
    }
    return os << "]";
}

#define deb(x) cerr << #x << " = " << x << endl;

vi adj[100005];
vi val;
vector<pair<int,int> > cnt;
map<ll,ll>m;
bool comp(pair<int,int>A,pair<int,int>B){
    return A.S>B.S;
}
int32_t main(){
	ios::sync_with_stdio(false);

    int t;
    cin>>t;

    while(t--){
        int n,M;
        cin>>n>>M;
        m.clear();
        REP(i,0,100005){
            adj[i].clear();
        }

        
        val.resize(n);
        cnt.clear();
        REP(i,0,n){
            cnt.PB({i,0});
        }

        REP(i,0,M){
            int u,v;
            cin>>u>>v;
            u--;
            v--;
            adj[u].PB(v);
            adj[v].PB(u);
            m[u]++;
            m[v]++;
            cnt[u].S++;
            cnt[v].S++;

        }
        REP(i,0,n){
            cin>>val[i];
        }

        sort(val.begin(),val.end());
        sort(cnt.begin(),cnt.end(),comp);
        ll ans=0;


        for(int i=0;i<cnt.size();i++){

            if(m[cnt[i].F]>0){
                ans+=m[cnt[i].F]*val[val.size()-1];
                val.pop_back();

                for(auto G:adj[cnt[i].F]){
                    m[G]--;
                }
            }
        }

        cout<<ans<<"\n";




    }


    return 0;
}