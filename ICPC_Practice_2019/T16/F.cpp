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



int32_t main(){
    ios::sync_with_stdio(false);
    int q;
    cin>>q;
    while(q--){
        int n;
        cin>>n;
        string s;
        string t;
        cin>>s>>t;
        string a, b;
        a=s;
        b=t;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        if(a!=b){
            cout<<"-1\n";
        }
        else{
            // for(int i=0;i<n;i++){
                // for(int j=0;j<n;j++){
                    // if(s[])
                // }
            // }
            int C=0;
            for(int i=0;i<n;i++){
                int ct=0;
                for(int j=0;j<n;j++){
                    if((i+ct)<n)
                    if(t[i+ct]==s[j]){
                        ct++;
                    }
                }
                C=max(ct,C);
            }
            int ans=n-C;
            cout<<ans<<"\n";
        }
    }

    return 0;
}