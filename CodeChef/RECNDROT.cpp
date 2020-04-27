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



int32_t main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    vector<int>a;
    set<int>S;
    map<int, int>M;
    vector<int>dp;
    while(t--){
        int n;
        cin>>n;
        M.clear();
        a.clear();
        dp.clear();
        dp.resize(n+1,-1);
        a.resize(n);
        S.clear();
        for(int i=0;i<n;i++){
            cin>>a[i];
            S.insert(a[i]);
        }
        int I=1;
        for(auto g:S){
            M[g]=I;
            I++;
        }
        for(int i=0;i<n;i++){
            a[i]=M[a[i]];
        }
        M.clear();
        for(int i=0;i<n;i++){
            //deb(i);
            // if(dp[a[i]-1]!=0){
            //     dp[a[i]]=max(dp[a[i]],dp[a[i]-1]+1);
            // }
            // else{
            //     dp[a[i]]=max(dp[a[i]],0LL);
            // }
            //deb(a[i]);
            if(a[i]==1){
                dp[a[i]]=max(dp[a[i]],0LL);
            }
            else{
                dp[a[i]]=max(dp[a[i]],dp[a[i]-1]+1);
            }
            //deb(dp[a[i]]);
        }
        //deb(a);
        int ans=S.size();
        //deb(ans);
        I=S.size();
        //deb(dp);
        while(I>=1){
            //deb(I);
            if(dp[I]!=0){
                ans-=dp[I];
                I-=dp[I];
            }
            //deb(ans);
            I--;
        }
        cout<<ans<<"\n";


    }

    return 0;
}