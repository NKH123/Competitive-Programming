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

bool year(int a, int b){
    if(b>=1 && b<=12){
        return true;
    }
    return false;
}
bool month(int a, int b){
    if(a>=1 && a<=12){
        return true;
    }
    return false;
}
int32_t main(){
	ios::sync_with_stdio(false);
    string s;
    cin>>s;
    int A, B;
    for(int i=0;i<4;i++){
        if((s[i]-'0')>9 || (s[i]-'0')<0){
            cout<<"NA\n";
            return 0;
        }
    }
    A=(s[0]-'0')*10+(s[1]-'0');
    B=(s[2]-'0')*10+(s[3]-'0');
    if(month(A,B) && !year(A,B)){
        cout<<"MMYY\n";
    }
    else if(!month(A,B) && year(A,B)){
        cout<<"YYMM\n";
    }
    else if(month(A,B) && year(A,B)){
        cout<<"AMBIGUOUS\n";
    }
    else{
        cout<<"NA\n";
    }


	return 0;
}