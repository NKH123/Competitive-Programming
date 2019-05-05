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
    int h,w,n;
    cin>>h>>w>>n;
    int sr, sc;
    cin>>sr>>sc;
    string s,t;
    cin>>s;
    cin>>t;
    //up
    int R=sr,C=sc;
    int f=0;
    for(int i=0;i<n;i++){
        if(s[i]=='U'){
            R--;
        }
        if(R<=0){
            f=1;
            break;
        }
        if(t[i]=='D' && R!=h){
            R++;
        }
        
    }
    if(f==1){
        // deb("up");
        cout<<"NO\n";
        return 0;
    }

    //down
     R=sr,C=sc;
    for(int i=0;i<n;i++){
        if(s[i]=='D'){
            R++;
        }
        if(R>h){
            f=1;
            break;
        }
        if(t[i]=='U' && R!=1){
            R--;
        }
        
    }
    if(f==1){
        // deb("down");
        cout<<"NO\n";
        return 0;
    }

    //left
    R=sr,C=sc;
    for(int i=0;i<n;i++){
        if(s[i]=='L'){
            C--;
        }
        if(C<=0){
            f=1;
            break;
        }
        if(t[i]=='R' && C!=w){
            C++;
        }
        
    }
    if(f==1){
        // deb("left");
        cout<<"NO\n";
        return 0;
    }

    //right

    R=sr,C=sc;
    for(int i=0;i<n;i++){
        if(s[i]=='R'){
            C++;
        }
        if(C>w){
            f=1;
            break;
        }
        if(t[i]=='L' && C!=1){
            C--;
        }
        
    }
    if(f==1){
        // deb("right");
        cout<<"NO\n";
        return 0;
    }
    cout<<"YES\n";




	return 0;
}