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
    vi a(n);
    REP(i,0,n){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    map<int, multiset<int> >M;
    int sum[200005];
    memset(sum,0,sizeof(sum));
    for(int i=0;i<n;i++){
        int A=a[i];
        int ct=0;
        while(A>=0){
            
            if(M[A].size()<k){
                M[A].insert(ct);
                sum[A]+=ct;
            }
            else{

            }
            if(A==0){
                break;
            }
            A=A/2;
            ct++;

        }
    }
    int ans=1e18;
    for(int i=0;i<=(200005);i++){

        if(M[i].size()<k){
            continue;
        }
        else{
            ans=min(ans,sum[i]);
        }
    }
    cout<<ans<<"\n";
    return 0;
}