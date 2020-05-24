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
string s;
bool check(){
    int I=0;
    int F=0;
    int M=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='F'){
            F=1;
        }
        else{
            M=1;
        }
    }
    if(F+M==1){
        return true;
    }
    if(s=="F"){
        return true;
    }
    for(int i=0;i<s.size();i++){
        if(s[i]=='M'){
            I=i;
            break;
        }
    }
    for(int i=I;i<s.size();i++){
        if(s[i]!='M'){
            return false;
        }
    }
    return true;
}
void transform(){
    for(int i=s.size()-1;i>0;i--){
        if(s[i]=='F' && s[i-1]=='M'){
            swap(s[i],s[i-1]);
            i--;
        }
    }
}
int32_t main(){
    ios::sync_with_stdio(false);
    int mini=0;
    cin>>s;
    while(1){
        if(check()){
            break;
        }
        else{
            mini++;
            transform();
            deb(s);
        }
    }
    cout<<mini<<"\n";
    return 0;
}