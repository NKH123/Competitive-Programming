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
    vi a, b;
    vi dp;
    while(t--){
        int n;
        cin>>n;
        a.clear();
        b.clear();
        a.resize(n);
        b.resize(n);
        dp.clear();
        dp.resize(n);
        int ans=0;
        int W=0;
        for(int i=0;i<n;i++){
            dp[i]=i;
        }
        for(int i=0;i<n;i++){
            cin>>a[i]>>b[i];
        }
        if(b[n-1]>a[0]){
            W=1;
        }
        for(int i=1;i<n;i++){
            if(b[i-1]>a[i]){
                dp[i]=dp[i-1];
            }
        }
        deb(dp);
        for(int i=0;i<n;i++){
            if(i==0){
                if(b[n-1]>a[0]){
                    dp[i]=dp[n-1];
                }
            }
            else{
                if(b[i-1]>a[i]){
                    dp[i]=dp[i-1];
                }
            }
        }
        deb(dp);
        if(n==1){
            cout<<a[0]<<"\n";
            continue;
        }
        else{
            if(dp[0]==dp[n-1]){
                int l=n-1;
                for(int i=n-2;i>=0;i--){
                    if(dp[i]==dp[i+1]){
                        l=i;
                    }
                    else{
                        break;
                    }
                }
                if(l==0){
                    //find min
                    int mini=1e18;
                    for(int i=0;i<n;i++){
                        mini=min(mini,a[i]);
                    }
                    cout<<mini<<"\n";
                }
                else{
                    ans+=a[l];
                    int I=0;
                    while(dp[I]==dp[0]){
                        I++;
                    }
                    ans+=a[I];
                    for(int i=I+1;i<l;i++){
                        if(dp[i]!=dp[i-1]){
                            ans+=dp[i];
                        }
                    }
                    cout<<ans<<"\n";
                }
            }
            else{
                ans=0;
                ans+=dp[0];
                for(int i=1;i<n;i++){
                    if(dp[i]!=dp[i-1]){
                        ans+=dp[i];
                    }
                }
                cout<<ans<<"\n";
            }
        }

    }

    return 0;
}