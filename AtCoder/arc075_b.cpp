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
int times=0;
int n, A, B;
vi a;
bool check(int t){
    vi b(n);
    REP(i,0,n){
        b[i]=a[i]-t*B;
    }
    int hav=t;
    for(int i=n-1;i>=0;i--){
        if(b[i]<=0){
            break;
        }
        else{
            int req=0;
            req=b[i]/(A-B);
            if((b[i]%(A-B))!=0){
                req++;
            }
            b[i]=0;
            hav-=req;
            if(hav<0){
                return false;
            }
        }
    }
    if(hav>=0){
        return true;
    }
    else{
        return false;
    }
}

int32_t main(){
	ios::sync_with_stdio(false);

    cin>>n>>A>>B;
    a.resize(n);
    REP(i,0,n){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    int l=0, r=2*(a[n-1]/B+1)+1;
    int ans=a[n-1]/B+1;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)){
            ans=min(ans, mid);
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }

    cout<<ans<<"\n";
    return 0;
}