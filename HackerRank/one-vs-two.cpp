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

vi fact(1005);
int gcdExtended(int a, int b, int *x, int *y) 
{ 
    // Base Case 
    if (a == 0) 
    { 
        *x = 0, *y = 1; 
        return b; 
    } 
  
    int x1, y1; // To store results of recursive call 
    int gcd = gcdExtended(b%a, a, &x1, &y1); 
  
    // Update x and y using results of recursive 
    // call 
    *x = y1 - (b/a) * x1; 
    *y = x1; 
  
    return gcd; 
} 

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
int modInverse(int b, int m) 
{    
    int x, y; // used in extended GCD algorithm 
    int g = gcdExtended(b, m, &x, &y); 

    // Return -1 if b and m are not co-prime 
    if (g != 1) 
        return -1; 

    // m is added to handle negative x 
    return (x%m + m) % m; 
} 
int modDivide(int a, int b, int m) 
{ 
    a = a % m; 
    int inv = modInverse(b, m); 
    // if (inv == -1) 
    //    cout << "Division not defined"; 
    // else
       /*cout << "Result of division is " << */
    return (inv * a) % m; 
} 

int32_t main(){
	ios::sync_with_stdio(false);
    int n;
    cin>>n;
    vi a(n);
    REP(i,0,n)cin>>a[i];
    sort(a.begin(),a.end());
    int twos=0;
    for(int i=0;i<n;i++){
        if(a[i-1]==a[i]){
            twos++;
        }
    }
    int ones=n-ones;
    fact[0]=1;
    for(int i=1;i<1005;i++){
        fact[i]=(i*fact[i-1])%mod;
    }
    //deb(fact);
    // int total=modDivide(fact[n],power(2,twos),mod);
    int total=fact[n]/power(2,twos);
    // deb(total);
    // deb(twos);
    for(int i=0;i<twos;i++){
        int num=fact[twos];
        int den=(fact[twos-(i+1)]*fact[i+1])%mod;
        int nCr=modDivide(num,den,mod);
        int res=(nCr*fact[n-(i+1)])%mod;
        int rres=modDivide(res,power(2,twos-(i+1)),mod);
        //  int num=fact[twos];
        // int den=(fact[twos-(i+1)]*fact[i+1]);
        // int nCr=num/den;
        // int res=(nCr*fact[n-(i+1)]);
        // int rres=res/power(2,twos-(i+1));

        if(i%2==0){
            total=(total-rres+mod)%mod;
            // total-=rres;

        }
        else{
            // total+=rres;
            total=(total+rres)%mod;
        }
    }
    cout<<total<<"\n";
    return 0;
}