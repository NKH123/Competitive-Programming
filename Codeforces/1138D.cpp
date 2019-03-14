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
    cin>>s;
    cin>>t;
    int ct00=0,ct01=0,ct10=0,ct11=0;
    REP(i,0,s.size()){
        if(s[i]=='0'){
            ct00++;
        }
        else{
            ct01++;
        }
    }
    REP(i,0,t.size()){
        if(t[i]=='0'){
            ct10++;
        }
        else{
            ct11++;
        }
    }
    if(ct10 >ct00 || ct11 >ct01){
        cout<<s<<"\n";
    }
    else{
        int times;
        if(ct10!=0){
            times=ct00/ct10;
        }
        if(ct11!=0){
            times=min(times,ct01/ct11);
        }
        for(int i=0;i<times;i++){
            ct00-=ct10;
            ct01-=ct11;
            cout<<t;
        }
        while(ct00>0){
            cout<<0;
            ct00--;
        }
        while(ct01>0){
            cout<<1;
            ct01--;
        }
        cout<<"\n";
      

    }
	return 0;
}