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



int32_t main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    vi a;
    map<int, int>m;
    while(t--){
        int n, k;
        cin>>n>>k;
        a.clear();
        a.resize(n);
        m.clear();
        REP(i,0,n){
            cin>>a[i];
            m[a[i]]++;
        }
        int no1=0;
        int nd=0;
        for(auto g:m){
            nd++;
            if(g.S==1){
                no1++;
            }
        }
        for(auto g:m){
            if(g.S!=1){
                if(k>=g.S){
                    int upd=g.S;
                    no1+=upd;
                    g.S=1;
                    nd+=(upd-1);
                    k-=(upd-1);
                }
                else{
                    int upd=k;
                    no1+=k;
                    g.S=1;
                    nd+=(k-1);
                    k=0;
                }
            }
        }
        int ans=no1*(nd-1);

        for(auto g:m){
            if(g.S!=1)
            ans+=(g.S*(nd-1));
        }
        cout<<ans<<"\n";
    }

    return 0;
}