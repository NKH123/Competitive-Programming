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
    int t;
    cin>>t;
    vi a;
    vi feed;
    while(t--){
        int n;
        cin>>n;
        int m;
        cin>>m;
        feed.clear();
        feed.resize(n+1,0);
        a.clear();
        a.resize(m);
        REP(i,0,m){
            cin>>a[i];
        }
        int ff=1;
        for(int i=0;i<m;i++){
            int cur=a[i];
            int f=1;
            for(int j=1;j<=n;j++){
                if(feed[cur]>feed[j]){
                    // deb(cur);
                    // deb(j);
                    f=0;
                }
            }
            if(f==1){
                feed[cur]++;
            }
            else{
                ff=0;
                break;
            }
        }
        if(ff==0){
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n";
        }
        
    }



    return 0;
}