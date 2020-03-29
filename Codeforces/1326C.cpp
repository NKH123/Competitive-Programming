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
#define mod 998244353
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
    int n, k;
    cin>>n>>k;
    set<int>S;
    vi a(n);
    REP(i,0,n){
        cin>>a[i];
    }
    int ans=0;
    REP(i,0,k){
        S.insert(a[i]);
        ans+=a[i];
    }
    for(int i=k;i<n;i++){
        int small=*S.begin();
        if(a[i]<small){
            continue;
        }
        else{
            ans-=small;
            ans+=a[i];
            S.erase(S.begin());
            S.insert(a[i]);
        }
    }
    vi mark(n,0);
    REP(i,0,n){
        if(S.find(a[i])!=S.end()){
            mark[i]=1;
        }
    }
    cout<<ans<<" ";
    ans=1;
    int ct=0;
    int f=0;
    // deb(mark);
    for(int i=0;i<n;i++){
        // deb(i);
        // deb(f);
        ct++;
        if(mark[i]==1 && f==0){
            ct=0;
            f=1;
        }
        else if(mark[i]==1 && f==1){
            // deb(ct);
            ans=(ans*ct)%mod;
            // f=0;
            ct=0;
        }

    }
    cout<<ans<<"\n";

    return 0;
}