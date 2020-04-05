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
vi a;
void gen(int ndig, int n){
    a.PB(n);

    if(ndig==10){
        return;
    }
    else{
        int dig=n%10;
        if(dig==0){
            gen(ndig+1,n*10+dig);
            gen(ndig+1,n*10+dig+1);
        }
        else if(dig==9){
            gen(ndig+1,n*10-1+dig);
            gen(ndig+1,n*10+dig);
        }
        else{
            gen(ndig+1,n*10+1+dig);
            gen(ndig+1,n*10-1+dig);
            gen(ndig+1,n*10+dig);
        }

    }
}
int32_t main(){
    ios::sync_with_stdio(false);
    int k;
    cin>>k;
    for(int i=1;i<=9;i++){
        gen(1,i);
    }
    k--;
    sort(a.begin(),a.end());
    vi b;
    int l=0;
    b.PB(1);
    for(int i=0;i<a.size();i++){
        if(a[i]==b[b.size()-1]){

        }
        else{
            b.PB(a[i]);
        }
    }
    cout<<b[k]<<"\n";

    return 0;
}