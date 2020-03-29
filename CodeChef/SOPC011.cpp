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
vector<vector<int> >dp;
vi a;
vector<int>pp;
int lan=0;
void cons(int I){
    if(I<0){
        return;
    }
    if(dp[I][0]>=dp[I][1]){
        lan++;
        cons(I-1);
    }   
    else{
        lan++;
        pp.PB(I);
        cons(I-2);
    }
}

int32_t main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;

    while(t--){
        a.clear();
        dp.clear();
        int n;
        cin>>n;
        a.resize(n);
        REP(i,0,n){
            cin>>a[i];
        }
        dp.resize(n,vector<int>(2,-1));
        dp[0][0]=a[0];
        dp[0][1]=a[0];
        for(int i=1;i<n;i++){
            dp[i][0]=a[i]+max(dp[i-1][0],dp[i-1][1]);
            if(i>1)
                dp[i][1]=a[i]*a[i-1]+max(dp[i-2][0],dp[i-2][1]);
            else{
                dp[i][1]=a[i]*a[i-1];
            }
        }
        cout<<max(dp[n-1][0],dp[n-1][1])<<" ";
        lan=0;
        pp.clear();
        cons(n-1);
        cout<<lan<<"\n";
        // deb(pp);
        cout<<pp.size()<<"\n";
        for(int i=(int)pp.size()-1;i>=0;i--){
            cout<<pp[i]<<" "<<(pp[i]+1)<<"\n";
        }
    }

    return 0;
}