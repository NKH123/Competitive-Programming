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
    int n, m, h;
    cin>>n>>m>>h;
    vi a(m);
    REP(i,0,m)cin>>a[i];
    vi b(n);
    REP(i,0,n)cin>>b[i];
    vector<vi>Top(n,vector<int>(m));
    REP(i,0,n){
        REP(j,0,m){
            cin>>Top[i][j];
        }
    }

    vector<vi>mat(n,vector<int>(m));
    vector<bool>A(m,false);
    vector<bool>B(n,false);
    for(int i=0;i<n;i++){
        if(B[i]==true)continue;
        for(int j=0;j<m;j++){
            if(A[j]==true)continue;
            if(b[i]==a[j] && Top[i][j]!=0 ){
                mat[i][j]=a[j];
                A[j]=true;
                B[i]=true;
            }
        }
    }
    for(int i=0;i<m;i++){
        if(A[i]==true)continue;
        for(int j=0;j<n;j++){
            if(Top[j][i]==0 || mat[j][i]!=0 || a[i]>b[j])continue;
            else{
                mat[j][i]=a[i];
                A[i]=true;
            }
        }
    }

    // deb("here");
    for(int i=0;i<n;i++){
        if(B[i]==true)continue;
        for(int j=0;j<m;j++){
            if(Top[i][j]==0 || mat[i][j]!=0 || b[i]>a[j])continue;
            else{
                mat[i][j]=b[i];
                B[i]=true;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]==0 &&(Top[i][j]!=0)){
                mat[i][j]=min(a[j],b[i]);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<"\n";
    }



	return 0;
}