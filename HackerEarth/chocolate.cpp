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


int32_t main(){
	ios::sync_with_stdio(false);
    int n;
    cin>>n;
    vi a(n+1);
    int sum=0;
    REP(i,0,n+1){
        cin>>a[i];
        sum+=a[i];
    }
    vi b;
    REP(i,0,n+1){
        b.PB(i);
    }
    double ans=0;
    ans+=a[0]*1.0/sum;
    do{
        double prob=1;
        int temp=sum;
        int i;
        if(b[0]==0)continue;
        for( i=0;i<n;i++){
            prob=prob*(a[b[i]]*1.0)/temp;
            temp-=a[b[i]];

            if(b[i]==0){
                break;
            }
        }

        ans+=(i+1)*prob;
    }while(next_permutation(b.begin(),b.end()));

     // cout<<setprecision(7)<<ans<<"\n";
    printf("%0.6lf\n",ans);

	return 0;
}       