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
#define llp 1000000007
#define mod 100

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
ll power(ll x, ll y) 
{
    ll temp;
    if( y == 0)
        return 1;
    temp = power(x, y/2);
    if (y%2 == 0)
        return (temp*temp)%mod;
    else
        return (((x*temp)%mod)*temp)%mod; 
}
ll power1(ll x, ll y) 
{  ll mod1=1e9+7;
    ll temp;
    if( y == 0)
        return 1;
    temp = power(x, y/2);
    if (y%2 == 0)
        return (temp*temp)%mod1;
    else
        return (((x*temp)%mod1)*temp)%mod1; 
}
ll power2(ll x, ll y) 
{  ll mod1=179426141;
    ll temp;
    if( y == 0)
        return 1;
    temp = power(x, y/2);
    if (y%2 == 0)
        return (temp*temp)%mod1;
    else
        return (((x*temp)%mod1)*temp)%mod1; 
}
int32_t main(){
	ios::sync_with_stdio(false);
    int n,q;
    cin>>n>>q;
    vi a(n);
    REP(i,0,n)cin>>a[i];
    vi par(n);
    par[0]=a[0];
    REP(i,1,n){
        par[i]=par[i-1]+a[i];
    }
   // deb(a);
   // deb(par);
    while(q--){
        int l1,r1,l2,r2,c;
        cin>>l1>>r1>>l2>>r2>>c;
        ll P,Q;
        if(l1!=1)
         P=par[r1-1]-par[l1-2];
        else
            P=par[r1-1];
        if(l2!=1)
         Q=par[r2-1]-par[l2-2];
        else
            Q=par[r2-1];
        //deb(q);
        //deb(P);
        //deb(Q);
        int C=power(P,Q);
        ll CC=power1(P,Q);
        ll CCC=power2(P,Q);
        C=C/10;
        if(CC<=9 && CCC<=9){
            cout<<"No "<<-1<<"\n";
        }
        else
        
        //deb(C);
    
        if(c==C){
            cout<<"Yes "<<c<<"\n";
        }
        else{
            
            cout<<"No "<<C<<"\n";
        }
        
    }



	return 0;
}