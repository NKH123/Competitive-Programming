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
#define mod 998244353
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

int fact[300005];

int32_t main(){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    string s;
    cin>>s;
    deque<int> r, g, b;
    for(int i=0;i<3*n;i++){
        if(s[i]=='R'){
            r.PB(i);
        }
        if(s[i]=='G'){
            g.PB(i);
        }
        if(s[i]=='B'){
            b.PB(i);
        }
    }
    int ct=0;
    vi bb(3*n,0);
    bb.clear();
    bb.resize(3*n,0);
    while(ct<n){
        deb(ct);
        deb(bb);
        int R=r.front();
        int G=g.front();
        int B=b.front();
        int Rb=r.back();
        int Gb=g.back();
        int Bb=b.back();
        if(R<=G && R<=B){
            bb[R]=1;
            r.pop_front();
            if(Gb>Bb){
                bb[Gb]=1;
                g.pop_back();
            }
            else{
                bb[Bb]=1;
                b.pop_back();
            }
        }
        else if(G<=R && G<=B){
            bb[G]=1;
            g.pop_front();
            if(Rb>Bb){
                bb[Rb]=1;
                r.pop_back();
            }
            else{
                bb[Bb]=1;
                b.pop_back();
            }

        }
        else if(B<=R && B<=G){
            bb[B]=1;
            b.pop_front();
            if(Rb>Gb){
                bb[Rb]=1;
                r.pop_back();
            }
            else{
                bb[Gb]=1;
                g.pop_back();
            }
        }
        deb(bb);

        deb("******");
        ct++;
    }
    fact[0]=1;
    for(int i=1;i<(300005);i++){
        fact[i]=(i*fact[i-1])%mod;
    }
    int ans=fact[n];
    int R=0;
    int G=0;
    int B=0;
    for(int i=0;i<3*n;i++){
        if(bb[i]==0){
            if(s[i]=='R'){
                R++;
            }
            if(s[i]=='G'){
                G++;
            }
            if(s[i]=='B'){
                B++;
            }
        }
    }
    ans=(ans*fact[R])%mod;
    ans=(ans*fact[G])%mod;
    ans=(ans*fact[B])%mod;
    cout<<ans<<"\n";

    return 0;
}