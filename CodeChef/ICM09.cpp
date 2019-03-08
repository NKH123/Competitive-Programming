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
    int t;
    cin>>t;
    vi a;
    vi par;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        a.resize(s.size());
        par.resize(n);
        REP(i,0,n){
            if(s[i]=='0'){
                a[i]=0;
            }
            else{
                a[i]=1;
            }

        }
        par[0]=a[0];
        REP(i,1,n){
            par[i]=par[i-1]+a[i];
        }
        int ans=0;
        int sum=0;
        int nsum=0;
        //deb(a);
        REP(i,0,n){
            sum+=a[i];
            nsum+=1-a[i];
            /*deb(i);
            deb(sum);
            deb(nsum);*/
            if(sum<nsum){
                while(sum<nsum){
                    sum++;
                    nsum--;
                    ans++;
                }
                
            }
        }
        cout<<ans<<"\n";

    }



	return 0;
}