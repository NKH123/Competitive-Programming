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
int t;
int n;
vi a;
bool eve(int A){
    int len=0;
    int B=A;
    while(B>=0){
        len++;
        B=B/2;
        if(B==0)break;
    }
    for(int i=0;i<=len;i+=2){
        if((1LL<<i)&(A)!=0){
            return false;
        }
    }
    return true;
}
int make(int A){
    int len=0;
    int B=A;
    while(B>=0){
        len++;
        B=B/2;
        if(B==0)break;
    }
    B=A;
    for(int i=0;i<=len;i+=2){
        if((1LL<<i)&(B)!=0){
            B=B^(1LL<<i);
        }
    }
    for(int i=0;i<=len;i++){
        if(i%2==1){
            B=B|(1LL<<i);
            if(B>=A){
                return B;
            }
            else{
                B=B^(1LL<<i);
            }
        }
    }
}
int32_t main(){
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        cin>>n;
        a.resize(n+1);
        a[0]=0;
        int sum=0;
        REP(i,1,n+1)cin>>a[i];
        for(int i=1;i<=n;i++){
            if(a[i]==-1){
                a[i]=a[i-1];
                int val=a[i-1];
                if(eve(val)){
                    continue;
                }
                else{
                   a[i]=make(val);
                }
            }
            sum+=a[i];
        }
        deb(a);
        cout<<sum<<"\n";
    }



    return 0;
}