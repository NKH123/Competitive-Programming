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


int main(){
	ios::sync_with_stdio(false);

    int n,v;
    cin>>n>>v;
    int rem=n-1;
    /*for(int i=1;i<n;i++){

    }*/
    if(v>rem){
        cout<<rem<<"\n";
        return 0;
    }
    int cur=0;
    int curp=1;
    ll ans=0;
    /*while(rem>0){
        cur=min(v,cur+min(rem,v));
        deb(rem);
        deb(cur);
        if(!(cur>rem))
        ans=ans+curp*(min(v,rem-cur));
        deb(ans);
        rem--;
        curp++;
        cur--;
    }*/
    ans+=v;
    //ans+=(n-(v+1));
    int K=n-(v+1);
    for(int i=0;i<(n-(v+1));i++){
        ans+=i+2;
    }
    cout<<ans<<"\n";


	return 0;
}