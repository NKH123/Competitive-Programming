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

int lcm(int a,int b){
    int ans=(a*b);
    ans=ans/__gcd(a,b);
    return ans;
}

int32_t main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    vector<int>A;
    vector<int>par;
    while(t--){
        int a, b, q;
        cin>>a>>b>>q;
        par.clear();
        A.clear();
        int n=lcm(a,b);
        par.resize(n);
        A.resize(n);
        for(int i=0;i<n;i++){
            if(((i%a)%b)!=((i%b)%a)){
                par[i]=1;
                A[i]=1;
            }
        }
        for(int i=1;i<n;i++){
            par[i]+=par[i-1];
        }
        while(q--){
            int l, r;
            cin>>l>>r;
            int len=r-l+1;
            int ans=0;
            if(len<=(n)){

                int L=l%n;
                int R=r%n;
                if(L<=R){
                    ans+=(par[R]);
                    if(L!=0){
                        ans-=(par[L-1]);
                    }
                }
                else{
                    ans+=(par[n-1]);
                    if(L!=0){
                        ans-=par[L-1];
                    }
                    ans+=par[R];
                }
            }
            else{
                int L=l%n;
                if(L!=0){
                    ans+=par[n-1];
                    ans-=par[L-1];
                }
                int R=r%n;
                if(R!=(n-1)){
                    ans+=par[R];
                }
                
                int LL=l;
                int RR=r;
                if(L!=0){
                    LL+=(n-l%n);
                }
                if(R!=(n-1)){
                    RR-=((r%n)+1);
                }
                int len=(RR-LL+1);
                int times=len/n;
                ans+=(times*(par[n-1]));


            }
            cout<<ans<<"\n";
        }
    }

    return 0;
}