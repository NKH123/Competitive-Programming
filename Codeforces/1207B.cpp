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


int a[55][55];
int b[55][55];
int32_t main(){
    ios::sync_with_stdio(false);
    int n, m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    memset(b,0,sizeof(b));
    vector<pair<int, int > >ans;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]==1){
                if(b[i][j]==0){
                    if(i==(n-1) || (j==(m-1))){
                        cout<<"-1\n";
                        return 0;
                    }
                    else{
                        if(a[i][j+1]!=1 || a[i+1][j]!=1 || a[i+1][j+1]!=1){
                            cout<<"-1\n";
                            return 0;
                        }
                        else{
                            b[i][j]=1;
                            b[i][j+1]=1;
                            b[i+1][j]=1;
                            b[i+1][j+1]=1;
                            ans.PB({i+1,j+1});
                        }
                    }
                }
                else{
                    if(i==(n-1) || (j==(m-1))){
                      continue;
                  }
                  if(a[i][j+1]==1 && a[i+1][j]==1 && a[i+1][j+1]==1){
                    b[i][j]=1;
                    b[i][j+1]=1;
                    b[i+1][j]=1;
                    b[i+1][j+1]=1;
                    ans.PB({i+1,j+1});
                }
            }
        }
    }
}
cout<<ans.size()<<"\n";
for(int i=0;i<ans.size();i++){
    cout<<ans[i].F<<" "<<ans[i].S<<"\n";
}



return 0;
}