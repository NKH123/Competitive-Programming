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
#define endl "\n"
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


long waitingTime(vector<int> t, int p) {
    int ans=0;
    for(int i=0;i<p;i++){
        if(t[i]<t[p]){
            ans+=t[i];
        }
        else{
            ans+=t[p];
        }
    }
    ans+=t[p];
    for(int i=p+1;i<t.size();i++){
        if(t[i]<(t[p]-1)){
            ans+=(t[i]);
        }
        else{
            ans+=(t[p]-1);
        }
    }
    // deb("2");
    return ans;
}

long brute(vector<int> t, int p){
    int rem=t[p];
    int ans=0;
    // deb("2");
    while(t[p]>0){
        for(int i=0;i<t.size();i++){
            if(t[i]>0){
                t[i]--;
                ans++;
            }
            if(t[p]==0){
                return ans;
            }
        }
    }
    // deb("1");
    return ans;
}

int32_t main(){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    vi v(n);
    REP(i,0,n){
        cin>>v[i];
    }
    // deb(v);
    // deb(n);
    int p;
    cin>>p;
    // deb(p);
    // deb("here");
    if(brute(v,p)!=waitingTime(v,p)){
        deb(v);
        deb(p);
    }
    else{
        deb(brute(v,p));
    }
    return 0;
}