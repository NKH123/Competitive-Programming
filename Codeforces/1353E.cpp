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

// vi a;
string s;

int32_t main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    vi act;
    vi com;
    vi pla;
    vi las;
    while(t--){
        int n, k;
        cin>>n>>k;
        cin>>s;
        act.clear();
        act.resize(k);
        las.clear();
        las.resize(k,-1);
        com.clear();
        com.resize(s.size());
        pla.clear();
        pla.resize(s.size());
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                if((i-k)>=0 && s[i-k]=='1'){
                    com[i]=com[i-k]+1;
                }   
                else{
                    com[i]=1;
                }
                act[i%k]++;
                las[i%k]=i;
            }
            pla[i%k]++;
        }
        for(int i=0;i<k;i++){
            int ct=0;
            int f=0;
            for(int j=i;j<las[i];j+=k){
                if(f==0){
                    if(s[j]=='1'){
                        f=1;
                    }
                }
                else{
                    if(s[j]=='0'){
                        ct++;
                    }
                }
            }
            // f=0;
            pla[i%k]=ct;

        }
        int tot=0;
        for(auto g:act){
            tot+=g;
        }
        int ans=tot;
        // deb(act);
        // deb(pla);
        for(int i=0;i<n;i++){
            if(s[i]=='0')continue;
            int temp=tot-act[i%k];
            temp=temp+(act[i%k]-com[i]);
            ans=min(ans,temp);
            ans=min(ans,(pla[i%k])+(tot-act[i%k]));
        }
        cout<<ans<<"\n";

    }

    return 0;
}