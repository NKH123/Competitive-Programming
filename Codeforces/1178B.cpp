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
    vi left(s.size());
    vi right(s.size());
    if(s.size()==0){
        cout<<0<<"\n";
        return 0;
    }
    left[0]=0;
    for(int i=1;i<s.size();i++){
        left[i]=left[i-1];
        if(s[i-1]=='v' && s[i]=='v'){
            left[i]++;
        }
    }
    right[(int)s.size()-1]=0;
    for(int i=(int)(s.size())-2;i>=0;i--){
        right[i]=right[i+1];
        if(s[i]=='v' && s[i+1]=='v'){
            right[i]++;
        }
    }
    int ans=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='o'){
            if(i==0 || i==(s.size()-1))continue;
            ans+=(left[i-1]*right[i+1]);
        }
    }
    cout<<ans<<"\n";



    return 0;
}