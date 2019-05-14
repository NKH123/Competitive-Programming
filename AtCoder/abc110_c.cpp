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
    string s;
    string t;
    cin>>s>>t;
    char a[26],b[26];
    for(int i=0;i<26;i++){
        a[i]='/';
        b[i]='/';
    }
    for(int i=0;i<s.size();i++){
        if(a[t[i]-'a']=='/'){
            a[t[i]-'a']=s[i];
        }
        else{
            if(a[t[i]-'a']!=s[i]){
                // deb(i);
                cout<<"No\n";
                return 0;
            }
        }
    }
    for(int i=0;i<s.size();i++){
        if(b[s[i]-'a']=='/'){
            b[s[i]-'a']=t[i];
        }
        else{
            if(b[s[i]-'a']!=t[i]){
                 // deb(i);
                cout<<"No\n";
                return 0;
            }
        }
    }
    // for(int i=0;i<26;i++){
    //     int f=0;
    //     for(int j=0;j<s.size();j++){
    //         if()
    //     }
    // }
    cout<<"Yes\n";


	return 0;
}