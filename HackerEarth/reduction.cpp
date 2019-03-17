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
bool check(vector<char>S ){
    char A=S[0];
    int f=1;
    for(int i=0;i<S.size();i++){
        if(S[i]!=A){
            f=0;
            return false;
        }
    }
    if(f){
        return true;
    }
}

int32_t main(){
	ios::sync_with_stdio(false);
    string s;
    cin>>s;
    set<char>ss;
    for(int i=0;i<s.size();i++){
        ss.insert(s[i]);
    }
    int ans=1e18;
    for(auto g:ss){
        string S=s;
        vector<char>T;
        T.clear();
        for(int i=0;i<s.size();i++){
            T.PB(s[i]);
        }
        int t=0;
        while(!check(T)){
            
            for(int i=0;i<(T.size()-1);i++){
                if(T[i]==g || T[i+1]== g){
                    T[i]=g;
                }
                
            }
            T.pop_back();

            t++;
        }
        // deb(t);
        // deb(T);
        ans=min(ans,t);
    }
    cout<<ans<<"\n";



	return 0;
}