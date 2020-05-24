#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAX 5000001
 
const int mod = 1e9+7;
 
int p[MAX]{0};
int m[MAX]{0};
int pf[MAX]{0};

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
 
int count(int n,int p){
    int ans=0;
    while(n%p==0){
        ans++;
        n/=p;
    }
    return ans;
}
 
void solve(){
    for(int i=2;i<MAX;i++){
        if(pf[i]==0){
            // deb(i);
            pf[i]=i;
            for(int j=i;j<MAX;j+=i){
                pf[j]=i;
            }

        }
        int P=pf[i];
        p[i]=(1+p[i/P]);
        m[i]=(p[i]+m[i-1]);

    }
}
 
signed main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    solve();
    while(t--){
        int a,b;
        cin>>a>>b;
        // deb(a);
        // deb(b);
        // deb(m[a]);
        // deb(m[b]);
        cout<<m[a]-m[b]<<"\n";
    }
    
    
    return 0;
}