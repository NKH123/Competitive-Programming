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


// map<pair<int, int>, int>dis;
int a[2005][2005];

int32_t main(){
    ios::sync_with_stdio(false);
    int n, x, y;
    cin>>n>>x>>y;
    memset(a,0,sizeof(a));
    REP(i,1,n+1){
        REP(j,i+1,n+1){
            int dis=min(j-i,abs(i-x)+1+abs(j-y));
            a[i][j]=dis;
        }
    }

    vi ans(n+1);
    REP(i,1,n+1){
        REP(j,i+1,n+1){
            // int dis=min(j-i,ans(i-x)+1+abs(j-y));
            // a[i][j]=dis;
            if(a[i][j]>=0 && a[i][j]<=n-1)
            ans[a[i][j]]++;
        }
    }

    // // ans[1]=n;
    // // ans[2]=n-2+1+1+1+1;''
    // // REP(i,1,n){
    // //     ans[i]=n-i;
    // // }
    // //LL
    // for(int i=1;i<=x;i++){
    //     for(int j=i+1;j<=x;j++){
    //         ans[abs(j-i)]++;
    //         if(abs(j-1)==1){
    //             cout<<"("<<i<<" "<<j<<")\n";
    //         }
    //     }
    // }
    // deb(ans);
    // //RR
    // for(int i=y+1;i<=n;i++){
    //     for(int j=i+1;j<=n;j++){
    //         ans[abs(j-i)]++;
    //         if(abs(j-1)==1){
    //             cout<<"("<<i<<" "<<j<<")\n";
    //         }
    //     }
    // }
    // deb(ans);

    
    // //LR
    // for(int i=1;i<x;i++){
    //     for(int j=y;j<=n;j++){
    //         ans[x-i+j-y+1]++;
    //         if(x-i+j-y+1==1){
    //             cout<<"("<<i<<" "<<j<<")\n";
    //         }
    //     }
    // }
    // deb(ans);
    // for(int i=1;i<x;i++){
    //     for(int j=x+1;j<y;j++){
    //         ans[j-i]++;
    //     }
    // }
    // for(int i=x;i<=y;i++){
    //     for(int j=i+1;j<=n;j++){
    //         if(abs(i-x+1+abs(j-y))<(abs(j-i))){
    //             if(abs(i-x+1+abs(j-y))==1){
    //                cout<<"("<<i<<" "<<j<<")\n";
    //             }
    //             ans[abs(i-x+1+abs(j-y))]++;
    //         }
    //         else{
    //             ans[abs(j-i)]++;
    //             if(abs(j-i)==1){
    //                 cout<<"("<<i<<" "<<j<<")\n";
    //             }
    //         }
    //     }
    // }
    // // for(int i=x;i<=y;i++){
    // //     for()
    // // }
    // deb(ans);
    // // ans[1]-=2;
    REP(i,1,n){
        cout<<ans[i]<<"\n";
    }
    // // cout<<"\n";
    // // if(x+1!=y)

    return 0;
}