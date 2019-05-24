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
    string s;
    cin>>s;
    int mvs=(n-11)/2;
    int ct=0;
    int dis=0;
    vi pos;
    REP(i,0,s.size()){
        if(s[i]=='8'){
            ct++;
            pos.PB(i);
        }
    }
    if(ct==0){
        cout<<"NO\n";
        return 0;
    }
    int las=pos[min((int)pos.size()-1,mvs)];

    // int gap=las-ct+1;
    int gap=0;
    for(int i=0;i<=las;i++){
        if(s[i]!='8'){
            gap++;
        }
    }

    // deb(gap);
    // deb(ct);
    // deb(mvs);
    // deb(gap);
    if(ct>mvs && gap<=mvs){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }



	return 0;
}