#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <b; i++)
typedef long long ll;
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
vi a={0,2,5,5,4,5,6,3,7,6};
bool comp(int A,int B){
    return a[A]<a[B];
}

int main(){
	ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;


    //deb(a);
    vi b(m);
    REP(i,0,m)cin>>b[i];
    sort(b.begin(),b.end(),comp);

    int times=n/a[b[0]];
    string ans="";
    REP(i,0,times){
        char add='0'+b[0];
        string Ad="a";
        Ad[0]=add;
        ans+=(Ad);
    }
    int prev=b[0];
    int rem=n%a[b[0]];
    int I=1;
    deb(n);
    deb(b);
    deb(a);
    deb("Outside");
    deb(rem);
    deb("i'm here");
    deb(ans);
    while(rem>0){
        deb(rem);
        times=rem/a[b[I]];
        REP(i,0,times){
            if(b[I]>=prev){
                char add='0'+b[I];
                string Ad="a";
                Ad[0]=add;
                ans=Ad+ans;
            }
            else{
                char add='0'+b[I];
                string Ad="a";
                Ad[0]=add;
                ans=ans+Ad;
            }
        }
        rem=rem%a[b[I]];
        I++;
    }
    cout<<ans<<"\n";

    return 0;
}


