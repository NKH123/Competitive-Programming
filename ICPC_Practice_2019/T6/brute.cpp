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
vi a;
int n, k;
bool check(){
    int f=1;
    for(int i=0;i<n;i++){
        int I=i+1;
        if(abs(a[i]-I)<k){
            f=0;
        }
    }
    if(f==0){
        return false;
    }
    else{
        return true;
    }
}


int32_t main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    
    while(t--){

        cin>>n>>k;
        a.clear();
        a.resize(n);
        REP(i,0,n){
            a[i]=i+1;
        }
        // deb(a);
        int f=0;
        do{
            if(check()){
                deb(a);
                f=1;
                break;
            }
        }while(next_permutation(a.begin(),a.end()));
        if(f==0){
            cout<<-1<<"\n";
        }
    }



    return 0;
}