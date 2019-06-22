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
#define sz(x) (int)(x.size())
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
    string s;
    cin>>s;
    vi pref(s.size()+1,0);
    vi suff(s.size()+1,0);
    for(int i=0;i<s.size();i++){
        if(s[i]=='Q'){
            pref[i+1]=pref[i]+1;
        }
        else{
            pref[i+1]=pref[i];
        }
    }
    for(int i=s.size()-1;i>=0;i--){
        if(i==(s.size()-1)){
            if(s[i]=='Q'){
                suff[i+1]=1;
            }
        }
        else{
            if(s[i]=='Q'){
                suff[i+1]=suff[i+2]+1;
            }
            else{
                suff[i+1]=suff[i+2];
            }
        }
    }
    int ans=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='A'){
            if(i!=(s.size()-1))
            ans+=(pref[i]*suff[i+2]);
        }
    }
    cout<<ans<<"\n";
    return 0;
}