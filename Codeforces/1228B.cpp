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
    int h, w;
    cin>>h>>w;
    vi r(h);
    REP(i,0,h){
        cin>>r[i];
    }
    vi c(w);
    REP(i,0,w){
        cin>>c[i];
    }
    vector<vector<int> >a(h,vector<int>(w,-1));
    for(int i=0;i<h;i++){
        for(int j=0;j<r[i];j++){
            a[i][j]=1;
        }
        if((r[i])<(w)){
            a[i][r[i]]=0;
        }
    }
    for(int i=0;i<w;i++){
        for(int j=0;j<c[i];j++){
            if(a[j][i]!=0)
            a[j][i]=1;
            else{
                cout<<0<<"\n";
                return 0;
            }
        }
        if(c[i]<h){
            
            if(a[c[i]][i]==1){
                cout<<0<<"\n";
                return 0;
            }
            a[c[i]][i]=0;
        }

    }
    int ans=1;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(a[i][j]==-1){
                ans=(ans*2)%mod;
            }
        }
    }
    cout<<ans<<"\n";



    return 0;
}