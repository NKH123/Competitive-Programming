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

int inverse(int a, int b)
{
    int inv = -1;
    int q, r, r1 = a, r2 = b, t, t1 = 0, t2 = 1;

    while (r2 > 0)
    {
        q = r1 / r2;
        r = r1 - q * r2;
        r1 = r2;
        r2 = r;

        t = t1 - q * t2;
        t1 = t2;
        t2 = t;
    }

    if (r1 == 1)
        inv = t1;

    if (inv < 0)
        inv = inv + a;

    return inv;
}
int gcd(int a, int b)
{
    int q, r;
    while (b > 0)
    {
        q = a / b;
        r = a - q * b;
        a = b;
        b = r;
    }
    return a;
}
int32_t main(){
	ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n, m, k;
        cin>>n>>m>>k;
        // deb(n);
        // deb(m);
        // deb(k);
        if(n%m==0){
            cout<<0<<"\n";
            continue;
        }
        int ans=0;
        int a=k;
        int b=n;
         n=m;
         //note now b in n not n
         int d=gcd(a,n);
         // deb(d);
         if((n%b==0) || (d%b==0)){
            cout<<-1<<"\n";
            continue;
         }
         int a1=a/d;
         int b1 =b/d;
         int n1=n/d;
         // deb(a1);
         // deb(b1);
         // deb(n1);
         int inv=inverse(n1,a1);
         int x0=(b1 * inv) % n1;
         int A=x0;
         int C=n/d;
         // deb(A);
         // deb(C);
         A=A%C;
         if(A<0){
            A+=C;
         }
         if(b-A*k <=0){
            cout<<-1<<"\n";
            continue;
         }
         else{
            cout<<A<<"\n";
            continue;
         }


    }



	return 0;
}