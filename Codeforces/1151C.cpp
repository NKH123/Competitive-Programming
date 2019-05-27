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

int SUM(int flag,int ind, int no){
    if(flag){
        int start=(2*ind-1+mod)%mod;
        int sum=((((start-2+mod)%mod)*(no%mod))%mod+((no%mod)*((no+1)%mod))%mod)%mod;
        return sum;
    }
    else{
        int start=(2*ind+mod)%mod;
        int sum=((((start-2+mod)%mod)*(no%mod))%mod+((no%mod)*((no+1)%mod))%mod)%mod;
        return sum;
    }
}
int sum(int x){
    int odd=1;
    int even=1;
    int f=1;
    int ret=0;
    for(int i=1;i<=x;i=i*2){
        // deb(i);
        if(f){
            ret+=SUM(1,odd,min((i*2)-i,x-i+1));
            odd+=(i*2)-i;

            f=0;
        }
        else{
            ret+=SUM(0,even,min((i*2)-i,x-i+1));
            even+=(i*2)-i;

            f=1;

        }
    }
    return ret;
}

int32_t main(){
	ios::sync_with_stdio(false);
    int l, r;
    cin>>l>>r;
    int ans=(sum(r)-sum(l-1)+mod)%mod;
    cout<<ans<<"\n";



	return 0;
}