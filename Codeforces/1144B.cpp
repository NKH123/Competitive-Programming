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
    vi a(n);
    REP(i,0,n){
        cin>>a[i];
    }
    vi eve, odd;
    for(int i=0;i<n;i++){
        if(a[i]%2==0){
            eve.PB(a[i]);
        }
        else{
            odd.PB(a[i]);
        }
    }
    sort(a.begin(),a.end());
    sort(eve.begin(),eve.end());
    sort(odd.begin(),odd.end());
    if(odd.size()==0 || eve.size()==0){
        int sum=0;
        for(int i=0;i<n-1;i++){
            sum+=a[i];
        }
        cout<<sum<<"\n";
        return 0;
    }
    int acc=max(eve.size(),odd.size())-min(eve.size(),odd.size());
    if(acc!=0){
        acc--;
    }
    int sum=0;
    if(eve.size()>odd.size()){
        for(int i=0;i<acc;i++){
            sum+=eve[i];
        }
    }
    else{
        for(int i=0;i<acc;i++){
            sum+=odd[i];
        }
    }
    cout<<sum<<"\n";




	return 0;
}