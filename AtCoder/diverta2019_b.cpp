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

int dp[15000];
int32_t main(){
	ios::sync_with_stdio(false);
    memset(dp,0,sizeof(dp));
    int R,G,B,N;
    cin>>R>>G>>B>>N;
    int Gmax=(N/(G))+1;
    int Bmax=(N/B)+1;
    for(int i=0;i<=(Gmax);i++){
        for(int j=0;j<=(Bmax);j++){
            int ans=i*G+j*B;
            dp[ans]+=1;
        }
    }
    int Rmax=(N/R)+1;
    int Ans=0;
    for(int i=0;i<=(Rmax);i++){
        int ans=N-(i*R);
        if(ans<0)continue;
        else{
            Ans+=dp[ans];
        }
    }
    cout<<Ans<<"\n";




	return 0;
}