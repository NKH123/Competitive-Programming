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
    int n;
    cin>>n;
    vector<string>t;
    t.resize(n);
    vector<vector<int> >ct(n,vector<int>(26,0));
    for(int i=0;i<n;i++){
        cin>>t[i];
         for(int j=0;j<t[i].size();j++){
            ct[i][t[i][j]-'a']++;
        }
    }
    vi a(26,0);
    for(int i=0;i<s.size();i++){
        a[s[i]-'a']++;
    }
    int ans=0;
    for(int i=0;i<(1<<n);i++){
        int f=1;
        int temp=__builtin_popcount(i);
        vector<int>b(26,0);
        for(int j=0;j<n;j++){
            if((i&(1LL<<j))!=0){
                for(int J=0;J<26;J++){
                    b[J]+=ct[j][J];
                }
            }
        }
        for(int J=0;J<26;J++){
            if(b[J]>a[J]){
                f=0;
            }
        }
        if(f==1)
        ans=max(ans,temp);
    }
    cout<<ans<<"\n";




    return 0;
}