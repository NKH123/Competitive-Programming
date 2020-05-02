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
    int t;
    cin>>t;
    vector<string >a;
    while(t--){
        int n, k;
        cin>>n>>k;
        a.clear();
        a.resize(k);
        string s;
        cin>>s;

        sort(s.begin(),s.end());
        if(k==1){
            cout<<s<<"\n";
            continue;
        }
        for(int i=0;i<k;i++){
            // a[i].PB(s[i]);
            a[i]+=s[i];
        }
        if(a[k-1]!=a[0]){
            cout<<a[k-1]<<"\n";
        }
        else{

            // int ct[26];
            // memset(ct,0,sizeof(ct));
            // vector<int>ct(26,0);
            string ans="";
            ans+=s[0];
            if(s[k]==s[s.size()-1]){
                for(int i=k;i<s.size();i+=k){
                    ans+=s[k];
                }
            }
            else{
                for(int i=k;i<s.size();i++){
                    ans+=s[i];
                }
            }
            cout<<ans<<"\n";
            
        }
    }
        //////deb(a);

    

    return 0;
}