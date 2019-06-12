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
int32_t main(){
    ios::sync_with_stdio(false);
    int q;
    cin>>q;
    int A;
    int i=1;
    while(q--){
        int A;
        cin>>A;
        int ans1=-1;
        if(__builtin_popcount(A+1)==1){      
            int ans=1;
            for(int i=2;i*i<=A;i++){
                if(A%i==0){
                    ans=max(ans,i);
                    int I=A/i;
                    ans=max(ans,I);
                }
            }
            ans1=ans;
        }
        int N=0;
        int ct=0;
        for(int i=26;i>=0;i--){
            if((A&(1<<i))!=0){
                ct=i;
                break;
            }
        }
        for(int i=0;i<=ct;i++){
            if((A&(1<<i))==0){
                N=N|(1<<i);
            }
        }
        if(ans1==-1)
        ans1=__gcd(N^A,A&N);
        cout<<ans1<<"\n";
    }
    return 0;
}