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
int f(int b, int n){
    if(n<b)return n;
    int ans=f(b,n/b)+n%b;
    return ans;
}

int32_t main(){
	ios::sync_with_stdio(false);
    int n, s;
    cin>>n>>s;
    
    if(s>n){
        cout<<-1<<"\n";
            return 0;
    }
    if(s==n){
        cout<<(n+1)<<"\n";
            return 0;
    }
  
    for(int i=2;i*i<=n;i++){

        if(f(i,n)==s){
            cout<<i<<"\n";
            return 0;
        }
    }
    int res=-1;
    for(int i=1;i*i<=(n-s);i++){
        if((n-s)%i==0){
            if(f(i+1,n)==s){
                if(res==-1 || res>(i+1)){
                    res=i+1;
                }
            }
            if(f(((n-s)/i)+1,n)==s){
                if(res==-1 || res>((n-s)/i)+1){
                    res=((n-s)/i)+1;
                }  
            }
        }
        
    }
  
    cout<<res<<"\n";


	return 0;
}