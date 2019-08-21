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
    vi pref(s.size(),0);
    vi suff(s.size(),0);
    if(s[0]>='a' && s[0]<='z'){
        pref[0]=1;
    }
    for(int i=1;i<s.size();i++){
        if(s[i]>='a' && s[i]<='z'){
            pref[i]=1;
        }
    }
    for(int i=1;i<s.size();i++){
        pref[i]=pref[i-1]+pref[i];
    }
    int n=s.size();
    if(s[n-1]>='A' && s[n-1]<='Z'){
        suff[n-1]=1;
    }
    for(int i=n-2;i>=0;i--){
        if(s[i]>='A' && s[i]<='Z'){
            suff[i]=1;
        } 
    }
    for(int i=n-2;i>=0;i--){
        suff[i]=suff[i]+suff[i+1];
    }
    int ans=suff[0];
    // ans=pref[0];//+suff[i+1];
    // if(s.size()>1){
    //     ans+=suff[1];
    // }
    for(int i=0;i<=(n-1);i++){
        if(i!=(n-1))
        ans=min(ans,pref[i]+suff[i+1]);
        else{
            ans=min(ans,pref[i]);
        }
    }
    cout<<ans<<"\n";



    return 0;
}