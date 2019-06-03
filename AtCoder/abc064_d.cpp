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
    int n;
    cin>>n;
    string s;
    cin>>s;
    deque<pair<char, int> >Se;
    for(int i=0;i<n;i++){
        if(s[i]=='('){
            if(Se.size()==0){
                Se.PB({'(',1});
            }
            else{
                Se.PB({'(',Se[Se.size()-1].S+1});
            }
        }
        else{
            if(Se.size()==0){
                Se.PB({'(',1});
                Se.PB({')',0});
            }
            else{
                if(Se[Se.size()-1].S==0){
                    Se.push_front({'(',1});
                    Se.PB({')',0});
                }
                else{
                    Se.PB({')',Se[Se.size()-1].S-1});
                }
            }
        }
    }
    if(Se[Se.size()-1].S!=0){
        int no=Se[Se.size()-1].S;
        for(int i=0;i<no;i++){
            Se.PB({')',Se[Se.size()-1].S-1});
        }
    }
    for(int i=0;i<Se.size();i++){
        cout<<Se[i].F;
    }
    cout<<"\n";
    return 0;
}