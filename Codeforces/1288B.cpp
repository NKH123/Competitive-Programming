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

int conc(int a, int b){
    int no=0;
    int A=a;
    while(A>0){
        no++;
        A=A/10;
    }
    int ans=a;
    for(int i=0;i<no;i++){
        ans=ans*10;
    }
    ans+=b;
    return ans;
}
bool check(int A){
    int f=1;
    while(A>0){
        if(A%10!=0 && A!=1){
            f=0;
        }
        A=A/10;
    }
    return f;
}
int32_t main(){
    ios::sync_with_stdio(false);
    int t;
    // for(int i=1;i<=1000;i++){
    //         for(int j=1;j<=1000;j++){
    //             if(( (i*j+i+j)==(conc(i,j)))){
    //                 cout<<i<<" "<<j<<"\n";
    //             }
    //         }
    //     }
    cin>>t;
    while(t--){
        int A, B;
        cin>>A>>B;
        int b=B;
        int no=0;
        while(b>0){
            b=b/10;
            no++;
        }
        no--;
        if(check(B+1)){
            no++;
        }
        int ans=A*no;
        cout<<ans<<"\n";

    }

    return 0;
}