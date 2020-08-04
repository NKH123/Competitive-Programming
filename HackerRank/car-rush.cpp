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

#define  deb(x) cerr << #x << " = " << x << endl;

int power(int x, int y){
    if(y==0){
        return 1LL;
    }
    else{
        int ans = power(x, y/2);
        ans= (ans*ans)%mod;
        if(y%2==1){
            ans=(ans*x)%mod;
        }
        return ans;
    }
}
int divi(int a, int b){
    int ans = (a*(power(b, mod-2)))%mod;
    return ans;
}
vi prefix_sum;
int32_t main(){
    ios::sync_with_stdio(false);
    int n , t;
    cin>>n>>t;
    t= 2*t;
    vector<pair<int, int> > a;
    a.resize(n);
    REP(i,0,n){
        cin>>a[i].S;
        a[i].S = 100-a[i].S;
        a[i].S=divi((long long)a[i].S,100LL);
    }
    REP(i,0,n){
        cin>>a[i].F;
    }
    
    sort(a.begin(),a.end());
    
    int ans = 0;
    int r = n;
    a.PB({1e18, 0});
    int val = 1e18;
    vi next_pos(n, -1);
    for(int i= n-1;i>=0;i--){
        while((a[r].F-a[i].F) >t){
            r--;
        }
        next_pos[i] = r;
    }
    prefix_sum.clear();
    prefix_sum.resize(n+1);
    prefix_sum[0]= a[0].S;
    for(int i=1;i<=n;i++){
        prefix_sum[i]=(prefix_sum[i-1] + a[i].S)%mod;
    }
    for(int i=0;i<n;i++){
        int temp = (1-a[i].S + 2*mod)%mod;
        int r= next_pos[i];
        int sum = (prefix_sum[r] - prefix_sum[i] +  2*mod)%mod;
        temp=(temp*sum)%mod;
        ans=(ans+temp)%mod;
    }
    cout<<ans<<"\n";
    return 0;
}