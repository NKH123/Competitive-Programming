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


void multiply(int F[2][2], int M[2][2]); 
  
/* Helper function that calculates F[][] raise to the power n and puts the 
  result in F[][] 
  Note that this function is designed only for fib() and won't work as general 
  power function */
void power(int F[2][2], int n); 
  
int fib(int n) 
{ 
  int F[2][2] = {{1,1},{1,0}}; 
  if (n == 0) 
      return 0; 
  power(F, n-1); 
  
  return F[0][0]; 
} 
  
void multiply(int F[2][2], int M[2][2]) 
{ 
  int x =  ((F[0][0]%mod)*(M[0][0]%mod))%mod + ((F[0][1]%mod)*(M[1][0]%mod)%mod); 
  int y =  ((F[0][0]%mod)*(M[0][1]%mod))%mod + ((F[0][1]%mod)*(M[1][1]%mod))%mod; 
  int z =  ((F[1][0]%mod)*(M[0][0]%mod))%mod + ((F[1][1]%mod)*(M[1][0]%mod))%mod; 
  int w =  ((F[1][0]%mod)*(M[0][1]%mod))%mod + ((F[1][1]%mod)*(M[1][1]%mod))%mod; 
  
  F[0][0] = x; 
  F[0][1] = y; 
  F[1][0] = z; 
  F[1][1] = w; 
} 
  
void power(int F[2][2], int n) 
{ 
  int i; 
  int M[2][2] = {{1,1},{1,0}}; 
  
  // n - 1 times multiply the matrix to {{1,0},{0,1}} 
  for (i = 2; i <= n; i++) 
      multiply(F, M); 
} 
  
vi aaa;
int32_t main(){
	ios::sync_with_stdio(false);

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        aaa.resize(n);
        REP(i,0,n)cin>>aaa[i];
        int ans=0;
        REP(i,0,n){
            REP(j,0,n){
                REP(k,0,n){
                   ans+=fib(aaa[i]+aaa[j]-aaa[k]);
                    if(ans>=mod){
                        ans-=mod;
                    }
                }
            }
        }
        cout<<(ans%mod)<<"\n";
    }


	return 0;
}