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
    int n, m;
    cin>>n>>m;
    vi b(n);
    priority_queue<int>pp;
    REP(i,0,n){
        cin>>b[i];
        pp.push(b[i]);
    }
    vi g(m);
    vector<bool>sat(m,1);
    REP(i,0,m)cin>>g[i];
    int ans=0;
    int sum=0;
    int mini=1e9;
    int maxi=-1;
    for(int i=0;i<n;i++){
        ans+=m*b[i];
        sum+=b[i];
        mini=min(mini,b[i]);
        maxi=max(maxi,b[i]);
    }
    for(int i=0;i<m;i++){
        if(g[i]>maxi){
            sat[i]=0;
        }
        if(g[i]<maxi){
            cout<<-1<<"\n";
            return 0;
        }
    }
    int ct=0;
    for(int i=0;i<m;i++){
        if(sat[i]==0){
            int ele=pp.top();
            ct++;
            ans=ans-ele+(g[i]);
            if(ct==(m-1)){
                pp.pop();
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}