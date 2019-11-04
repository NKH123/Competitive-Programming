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
int dp[105][105][105];
// int fun(int a, int b, int c){
//     if(a==0 && b==0 )
// }

int32_t main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    memset(dp,-1,sizeof(dp));
    while(t--){
        int a, b, c;
        cin>>a>>b>>c;

        int ans=0;
        int prevans=0;
        // while(1){
        //     if(b>c && a!=0){
        //         int take=min(a,b/2);
        //         ans+=3*take;
        //         b-=2*take;
        //         a-=take;
        //     }
        //     else{
        //         int take=min(b,c/2);
        //         ans+=3*take;
        //         b-=take;
        //         c-=2*take;

        //     }
        //     if(prevans==ans){
        //         break;
        //     }
        //     else{
        //         prevans=ans;
        //     }
        // }
        int f=1;
        do{
            prevans=ans;    
            int take=min(b,c/2);
            ans+=3*take;
            b-=take;
            c-=2*take;
        }while(prevans!=ans);
        do{
            prevans=ans;    
            int take=min(a,b/2);
            ans+=3*take;
            a-=take;
            b-=2*take;
        }while(prevans!=ans);
        // int ans=fun(a,b,c);
        cout<<ans<<"\n";

    }

    return 0;
}