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

map<int, int>M;
int32_t main(){
	ios::sync_with_stdio(false);
    int n;
    cin>>n;
    vi a(n);
    REP(i,0,n){
        cin>>a[i];
        M[a[i]]++;
    }
    int ct=0;
    int val=-1;
    for(auto g:M){
        if(g.S>ct){
            ct=g.S;
            val=g.F;
        }
    }
    int I=-1;
    for(int i=0;i<n;i++){
        if(a[i]==val){
            I=i;
            break;
        }
    }
    vector<pair<int, pair<int, int> > >ans;
    for(int i=I-1;i>=0;i--){
        if(a[i]>a[i+1]){
            ans.PB({2,{i+1,i+2}});
        }
        else if(a[i]<a[i+1]){
            ans.PB({1,{i+1,i+2}});
        }
        a[i]=a[I];
    }
    for(int i=I+1;i<n;i++){
        if(a[i]>a[i-1]){
            ans.PB({2,{i+1,i}});
        }
        else if(a[i]<a[i-1]){
            ans.PB({1,{i+1,i}});
        }
        a[i]=a[I];
    }
    cout<<ans.size()<<"\n";
    for(auto g:ans){
        cout<<g.F<<" "<<g.S.F<<" "<<g.S.S<<"\n";
    }




	return 0;
}