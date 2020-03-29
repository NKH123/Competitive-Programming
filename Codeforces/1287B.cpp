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
    int n, k;
    cin>>n>>k;
    vector<string>s;
    multiset<string>m;
    REP(i,0,n){
        string T;
        cin>>T;
        s.PB(T);
        m.insert(T);
    }
    int ans=0;
    int A='S'+'E'+'T';
    int f;
    for(int i=0;i<n;i++){
        m.erase(m.find(s[i]));
        for(int j=i+1;j<n;j++){
           f=1;
           m.erase(m.find(s[j]));
           if(s[i]==s[j]){
            if(m.find(s[i])!=m.end()){
                ans++;
            }
        }
        else{
            string T;
            for(int K=0;K<k;K++){
                
                if(s[i][K]==s[j][K]){
                    // f=0;
                    // break;
                    T+=s[i][K];
                }
                else{
                    T+=char(A-(s[i][K]+s[j][K]));
                }
            }
            if(f==1){
                // deb(i);
                // deb(j);
                // deb(s[i]);
                // deb(s[j]);
                // deb(T);
                if(m.find(T)!=m.end()){
                    ans++;
                }
            }

        }
    }
    m.clear();
    for(int j=i+1;j<n;j++){
        m.insert(s[j]);
    }
}
cout<<ans<<"\n";
return 0;
}