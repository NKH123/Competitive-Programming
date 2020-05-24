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


vector<vector<int> >a;
vector<vector<int> >Up;
vector<vector<int> >Down;
vector<vector<int> >Left;
vector<vector<int> >Right;
int32_t main(){
    ios::sync_with_stdio(false);

    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        a.clear();
        a.resize(n,vector<int>(m,0));
        Up.clear();
        Down.clear();
        Up.resize(n,vector<int>(m,0));
        Down.resize(n,vector<int>(m,0));
        Left.clear();
        Right.clear();
        Left.resize(n,vector<int>(m,0));
        Right.resize(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>a[i][j];
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(j==0){
                    Up[j][i]=a[j][i];
                }
                else{
                    Up[j][i]=min(a[j][i],a[j][i]+Up[j-1][i]);   
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(j==(0)){
                    Left[i][j]=a[i][j];
                }
                else{
                    Left[i][j]=min(a[i][j],a[i][j]+Left[i][j-1]);
                }
            }
        }
        for(int j=0;j<m;j++){
            for(int i=(n-1);i>=0;i--){
                if(i==(n-1)){
                    Down[i][j]=a[i][j];
                }
                else{
                    Down[i][j]=min(a[i][j],a[i][j]+Down[i+1][j]);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=(m-1);j>=0;j--){
                if(j==(m-1)){
                    Right[i][j]=a[i][j];
                }
                else{
                    Right[i][j]=min(a[i][j],a[i][j]+Right[i][j+1]);
                }
            }
        }
        int ans=1e18;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans=min(ans,Up[i][j]+Down[i][j]+Right[i][j]+Left[i][j]-3*a[i][j]);
            }
        }
        cout<<ans<<"\n";

    }


    return 0;
}