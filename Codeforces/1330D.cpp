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


int det_no_bits(int n){
    int ans=0;
    while(n>0){
        n=n/2;
        ans++;
    }
    return ans;
}
vi a;
int power(int a, int b){
    if(b==0){
        return 1LL;
    }
    else{
        int ans=power(a,b/2);
        ans=(ans*ans);
        if(b%2==1){
            ans=(a*ans);
        }
        return ans;

    }
}
int32_t main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int d, m;
        cin>>d>>m;
        int N=det_no_bits(d);
        a.clear();
        a.resize(64);
        for(int i=0;i<N-1;i++){
            a[i]=(power(2LL,i));
        }
        a[N-1]=d-(1LL<<(N-1))+1;
        vi ans(60);
        ans.clear();
        ans.resize(60);
        for(int i=60;i>=0;i--){
            ans[i]=a[i]%m;
            int mul=1%m;
            for(int j=i+1;j<=60;j++){
                mul=(mul+ans[j])%m;
            }
            ans[i]=(ans[i]*(mul))%m;
        }
        int Ans=0;
        for(int i=0;i<=60;i++){
            Ans=(Ans+ans[i])%m;
        }
        cout<<Ans<<"\n";
    }
    return 0;
}