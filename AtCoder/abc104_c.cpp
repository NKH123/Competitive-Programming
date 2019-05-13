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
    int d, g;
    cin>>d>>g;
    vi a;
    REP(i,0,d){
        a.PB(i);
    }
    vi p(d),c(d);
    REP(i,0,d){
        cin>>p[i]>>c[i];
    }
    int ans=1e18;
    do{
        int sum=0;
        int moves=0;
        for(int i=0;i<a.size();i++){
            //for(int j=0 )
            int need=g-sum;
            if(need>0){
                int mul=min((long long)ceil((1.0)*need/((a[i]+1)*100)),p[a[i]]);
                sum+=(mul)*(a[i]+1)*100;
                if(mul==p[a[i]]){
                    sum+=c[a[i]];
                }
                moves+=mul;
                if(sum>=g){
                    break;
                }
            }

        }
        ans=min(moves,ans); 
    }while(next_permutation(a.begin(),a.end()));
    cout<<ans<<"\n";

	return 0;
}