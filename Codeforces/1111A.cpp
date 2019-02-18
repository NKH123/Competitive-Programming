#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <b; i++)
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef pair<int,int> pi;
#define trace(x) cout<<#x<<"="<<x<<"\n";
#define print(x) cout<<#x<<" is "; for(int i=0;i<x.size();i++){cout<<x[i]<<" ";}cout<<"\n"
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


int main(){
	ios::sync_with_stdio(false);

    string s;
    string t;
    cin>>s>>t;
    int f=1;
    if(s.size()!=t.size()){
        cout<<"No\n";
        return 0;
    }
    else{
        string ss="aeiou";
        int ct=0;
        int ct1=0;
        REP(i,0,s.size()){
            REP(j,0,5){
                if(s[i]==ss[j])ct++;
            }
        }
        REP(i,0,s.size()){
            REP(j,0,5){
                if(t[i]==ss[j])ct1++;
            }
        }
        if(ct!=ct1){
            cout<<"No\n";
            return 0;
        }
        else{
                cout<<"Yes\n";
        return 0;
        }
    }


    return 0;
}