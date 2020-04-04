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
int t1[100005];
int t2[100005];
void build1(vector<int>a, int v, int tl, int tr) {
    if (tl == tr) {
        t1[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build1(a, v*2, tl, tm);
        build1(a, v*2+1, tm+1, tr);
        t1[v] = max(t1[v*2] , t1[v*2+1]);
    }
}
int sum1(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t1[v];
    }
    int tm = (tl + tr) / 2;
    return max(sum1(v*2, tl, tm, l, min(r, tm))
           , sum1(v*2+1, tm+1, tr, max(l, tm+1), r));
}
void build2(vector<int>a, int v, int tl, int tr) {
    if (tl == tr) {
        t2[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build2(a, v*2, tl, tm);
        build2(a, v*2+1, tm+1, tr);
        t2[v] = max(t2[v*2] , t2[v*2+1]);
    }
}
int sum2(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t2[v];
    }
    int tm = (tl + tr) / 2;
    return max(sum2(v*2, tl, tm, l, min(r, tm))
           , sum2(v*2+1, tm+1, tr, max(l, tm+1), r));
}
int32_t main(){
	ios::sync_with_stdio(false);
    int t;
    cin>>t;
    int T=t;
    while(t--){
        int n, k;
        cin>>n>>k;
        vi C(n);
        REP(i,0,n){
            cin>>C[i];
        }
        vi D(n);
        REP(i,0,n){
            cin>>D[i];
        }
        build1(C,1,0,n-1);
        build2(D,1,0,n-1);
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                if(abs(sum1(1,0,n-1,i-1,j-1)-sum2(1,0,n-1,i-1,j-1))<=k){
                    ans++;
                }
            }
        }
        cout<<"Case #"<<T-t<<": "<<ans<<"\n";

    }



	return 0;
}