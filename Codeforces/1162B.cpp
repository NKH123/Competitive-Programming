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


int32_t main(){
	ios::sync_with_stdio(false);
    int n, m;
    cin>>n>>m;
    vector<vector<int> >a(n);
    vector<vector<int> >b(n);
    REP(i,0,n){
        a[i].resize(m);
        REP(j,0,m){
            cin>>a[i][j];
        }
    }
    REP(i,0,n){
        b[i].resize(m);
        REP(j,0,m){
            cin>>b[i][j];
            if(a[i][j]>b[i][j]){
                swap(a[i][j],b[i][j]);
            }
        }
    }
    int f=1;
    for(int i=0;i<n;i++){
        for(int j=1;j<m;j++){
            if(a[i][j]<=(a[i][j-1])){
                // if(b[i][j]<=a[i][j-1]){
                //     f=0;
                // }
                // else if(b[i][j-1]){

                // }
                f=0;
            }
        }
    }
    for(int i=0;i<m;i++){
        for(int j=1;j<n;j++){
            if(a[j][i]<=(a[j-1][i])){
                f=0;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=1;j<m;j++){
            if(b[i][j]<=(b[i][j-1])){
                // if(b[i][j]<=a[i][j-1]){
                //     f=0;
                // }
                // else if(b[i][j-1]){

                // }
                f=0;
            }
        }
    }
    for(int i=0;i<m;i++){
        for(int j=1;j<n;j++){
            if(b[j][i]<=(b[j-1][i])){
                f=0;
            }
        }
    }
if(f==1){
    cout<<"Possible\n";
}
else{
    cout<<"Impossible\n";
}


	return 0;
}