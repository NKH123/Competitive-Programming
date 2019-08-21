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
    int q;
    cin>>q;
    vector<vector<int> >dp;
    while(q--){
        int n, k;
        cin>>n>>k;
        string s;
        cin>>s;
        dp.clear();
        dp.resize(n,vector<int>(3,0));
        //R case
        for(int i=(n-k);i<n;i++){
            if((i-(n-k))%3==0){
                if(s[i]!='R'){
                    dp[n-k][0]++;
                }
            }
            if((i-(n-k))%3==1){
                if(s[i]!='G'){
                    dp[n-k][0]++;
                }
            }
            if((i-(n-k))%3==2){
                if(s[i]!='B'){
                    dp[n-k][0]++;
                }
            }
        }
        for(int i=(n-k);i<n;i++){
            if((i-(n-k))%3==0){
                if(s[i]!='G'){
                    dp[n-k][1]++;
                }
            }
            if((i-(n-k))%3==1){
                if(s[i]!='B'){
                    dp[n-k][1]++;
                }
            }
            if((i-(n-k))%3==2){
                if(s[i]!='R'){
                    dp[n-k][1]++;
                }
            }
        }
        for(int i=(n-k);i<n;i++){
            if((i-(n-k))%3==0){
                if(s[i]!='B'){
                    dp[n-k][2]++;
                }
            }
            if((i-(n-k))%3==1){
                if(s[i]!='R'){
                    dp[n-k][2]++;
                }
            }
            if((i-(n-k))%3==2){
                if(s[i]!='G'){
                    dp[n-k][2]++;
                }
            }
        }
        int ans=min({dp[n-k][0],dp[n-k][1],dp[n-k][2]});
        // deb(dp[n-k]);
        int len=k%3;
        int L=n-k, R=n-1;
        while(L>0){
            L--;
            dp[L][0]=dp[L+1][1];
            if(s[L]!='R'){
                dp[L][0]++;
            }
            if(len==0){
                if(s[R]!='R'){
                    dp[L][0]--;
                }
            }
            else if(len==1){
                if(s[R]!='G'){
                    dp[L][0]--;
                }
            }
            else if(len==2){
                if(s[R]!='B'){
                    dp[L][0]--;
                }
            }
            dp[L][1]=dp[L+1][2];
            if(s[L]!='G'){
                dp[L][1]++;
            }
            if(len==0){
                if(s[R]!='G'){
                    dp[L][1]--;
                }
            }
            else if(len==1){
                if(s[R]!='B'){
                    dp[L][1]--;
                }
            }
            else if(len==2){
                if(s[R]!='R'){
                    dp[L][1]--;
                }
            }
             dp[L][2]=dp[L+1][0];
            if(s[L]!='B'){
                dp[L][2]++;
            }
            if(len==0){
                if(s[R]!='B'){
                    dp[L][2]--;
                }
            }
            else if(len==1){
                if(s[R]!='R'){
                    dp[L][2]--;
                }
            }
            else if(len==2){
                if(s[R]!='G'){
                    dp[L][2]--;
                }
            }
            // deb(L);
            // deb(dp[L]);
            ans=min({ans,dp[L][0],dp[L][1],dp[L][2]});




            R--;
        }
        cout<<ans<<"\n";
    }



    return 0;
}