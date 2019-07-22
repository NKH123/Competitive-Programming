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

set<int>S;
int32_t main(){
    ios::sync_with_stdio(false);
    int n, k;
    cin>>n>>k;
    vi a(n);
    REP(i,0,n){
        cin>>a[i];
        S.insert(a[i]);
    }
    if(S.size()<=k){
        cout<<0<<"\n";
    }
    else{
        vi b;
        b.PB(a[0]);
        for(int i=1;i<n;i++){
            if(a[i]!=b[b.size()-1]){
                b.PB(a[i]);
            }
        }
        vi inf(b.size()-1);
        int sum=0;
        for(int i=1;i<b.size();i++){
            sum+=(b[i]-b[i-1]);
            inf.PB(b[i]-b[i-1]);
        }
        sort(inf.begin(),inf.end());
        int I=inf.size()-1;
        int ct=0;
        int rem=0;
        while(ct<(k-1)){
            rem+=inf[I];
            I--;

            ct++;
        }
        sum-=rem;
        cout<<sum<<"\n";



    }

    return 0;
}