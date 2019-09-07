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


int getNo(int x1, int y1, int x2, int y2){
    int n1;
    if(y1==y2){
        n1=abs(x1-x2)+1;
    }
    else if(x1==x2){
        n1=abs(y1-y2)+1;
    }
    else{
        n1=__gcd(abs(x1-x2),abs(y1-y2))+1;
    }
    return n1;
}
int power(int a, int b){
    if(b==0){
        return 1LL;
    }
    else{
        int ans=power(a,b/2);
        ans=(ans*ans)%mod;
        if(b%2){
            ans=(ans*a)%mod;
        }
        return ans;
    }
}
int getAns(int N){
    if(N<2){
        return 0;
    }
    int ans=(((((N+mod)*(N-1+mod))%mod)*(N-2+mod))*(power(6LL,mod-2)))%mod;
    return ans;
}
int32_t main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int x1, x2, y1, y2, x3, y3;
        cin>>x1>>y1>>x2>>y2>>x3>>y3;
        int n1, n2, n3;
    //1 2
        n1=getNo(x1,y1,x2,y2);
    //1 3
        n2=getNo(x1,y1,x3,y3);
    // 2 3
        n3=getNo(x2,y2,x3,y3);
        int N=n1+n2+n3-3;
        N=N%mod;
        // deb(n1);
        // deb(n2);
        // deb(n3);
        // deb(N);
        // int ans=(((((N)*(N-1+mod))%mod)*(N-3+mod))*(power(3,mod-2)))%mod;
        int ans=getAns(N);
        // deb(ans);
        ans=(ans-getAns(n1)-getAns(n2)-getAns(n3)+5LL*mod)%mod;
        // deb(ans);
        cout<<ans<<"\n";

    }




    return 0;
}