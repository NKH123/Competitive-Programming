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
    vi a(n);
    REP(i,0,n)cin>>a[i];
    int l=0,r=n-1;
    vector<char>ans;
    int len=0;
    int cumin=-1;
    while(l<=r){
        // deb("in");
        // deb(l);
        // deb(r);
        // deb(ans);
        if(a[l]<a[r] && a[l]>cumin){
            ans.PB('L');
            len++;
                cumin=a[l];
            l++;
        
        }
        else if(a[l]>a[r] && a[r]>cumin) {
            ans.PB('R');
            len++;
              cumin=a[r];
            r--;
          
        }
        else if(a[l] >cumin){
             ans.PB('L');
            len++;
            cumin=a[l];
            l++;
            
        }
        else if(a[r]>cumin){
            ans.PB('R');
            len++;
            cumin=a[r];
            r--;
            
        }
        else{
            // deb(l);
            // deb(r);
            // deb(cumin);
            // deb("spec");
            break;
        }
        // deb("out");
        // deb(ans);
        

    }
    cout<<len<<"\n";
    REP(i,0,n)cout<<ans[i];
    cout<<"\n";


	return 0;
}