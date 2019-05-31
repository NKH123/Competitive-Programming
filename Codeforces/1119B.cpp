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
int n, h;
vi a;
bool comp(int aa, int bb){
    return aa>bb;
}
bool check(int k){
    vi A;
    A.clear();
    A.resize(k+1);
    REP(i,0,k+1){
        A[i]=a[i];
    }
    sort(A.begin(),A.end(),comp);
    int rem=h;
    for(int i=0;i<=k;i++){
        if(i%2==0){
            if(A[i]<=rem){

            }
            else{
                return false;
            }
        }
        else{
            if(A[i]<=rem){
                rem-=max(A[i-1],A[i]);
            }
            else{
                return false;
            }
        }
    }
    return true;
}

int32_t main(){
	ios::sync_with_stdio(false);

    cin>>n>>h;
    a.resize(n);
    REP(i,0,n)cin>>a[i];
    int l=0, r=n-1;
    int ans=-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }

    cout<<ans+1<<"\n";


    return 0;
}