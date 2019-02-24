#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <b; i++)
typedef long long ll;
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
    int n;
//int a[55][55];
//int b[55][55];
vector<vector<int> >a;
vector<vector<int> >b;
int id=11;
void dfs(int x,int y){
    if(x>n-1 || y>n-1 || x<0 || y<0 ||  b[x][y]!=-1 || a[x][y]==1 )return;
    b[x][y]=id;
    //dfs(x-1,y-1);
    dfs(x-1,y);
    //dfs(x-1,y+1);
    dfs(x,y-1);
    dfs(x,y+1);
    //dfs(x+1,y-1);
    dfs(x+1,y);
    //dfs(x+1,y+1);




}
int main(){
	ios::sync_with_stdio(false);


    cin>>n;
    int r1,c1,r2,c2;
    cin>>r1>>c1>>r2>>c2;
    r1--;
    c1--;
    r2--;
    c2--;
   /* memset(a,0,sizeof(a));
    memset(b,-1,sizeof(b));*/
    a.resize(n);
     b.resize(n);

    REP(i,0,n){
        a[i].resize(n);
        b[i].resize(n);
        REP(j,0,n){
            a[i][j]=0;
            b[i][j]=-1;
        }
    }
    REP(i,0,n){
        string s;
        cin>>s;
        for(int j=0;j<s.size();j++){
            if(s[j]=='1'){
                a[i][j]=1;
            }
        }
    }
    /*REP(i,0,n){
        deb(a[i]);
    }
    REP(i,0,n){
        deb(b[i]);
    }*/
    //deb(a);
    //deb(b);
    dfs(r1,c1);
    if(b[r2][c2]==11){
        cout<<0<<"\n";
        return 0;
    }
    /*deb("after");
    REP(i,0,n){
        deb(a[i]);
    }
    REP(i,0,n){
        deb(b[i]);
    }*/
    id++;
    dfs(r2,c2);
   /* deb("after second");
    REP(i,0,n){
        deb(a[i]);
    }
    REP(i,0,n){
        deb(b[i]);
    }*/
    ll ans=1e18;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            for(ll k=0;k<n;k++){
                for(ll l=0;l<n;l++){
                    if(b[i][j]==11 && b[k][l]==12){
                        ans=min(ans,(i-k)*(i-k)+(j-l)*(j-l));
                        //deb(ans);
                    }
                }
            }
        }
    }

    cout<<ans<<"\n";





	return 0;
}