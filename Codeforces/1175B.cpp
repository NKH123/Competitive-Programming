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
int MAX=(1ll<<32)-1;
int n;
int ans=0;
int f=0;
vi cur;
int ADD(int p){
    ans+=p;
    if(ans>MAX){
        f=1;
    }
}
int32_t main(){
	ios::sync_with_stdio(false);
    int l;
    cin>>l;
    cur.PB(1);
    int ff=0;
    int ind=0;
    while(l--){
        string s;
        cin>>s;
        if(s[0]=='f'){
            cin>>n;
            int add=cur[cur.size()-1]*n;
            if(add>MAX && ff==0){
                ff=1;
                ind=cur.size();
            }
            cur.PB(add);    
            
        }
        else if(s[0]=='e'){
            if(ind+1==cur.size()){
                ff=0;
            }
            cur.pop_back();
        }
        else if(s[0]=='a'){
            if(ff==1){
                f=1;
            }
            ADD(cur[cur.size()-1]);
        }
    }
    if(f==1){
        cout<<"OVERFLOW!!!\n";
        return 0;
    }
    cout<<ans<<"\n";

    return 0;
}