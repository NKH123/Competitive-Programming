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

vi a;
vi aa(100005);
vi Ni;
int32_t main(){
	ios::sync_with_stdio(false);
    int n;
    cin>>n;
    // memset(aa,0,sizeof(aa));
    aa.clear();
    aa.resize(100005);
    Ni.resize(n);
    a.resize(n);
    REP(i,0,n){
        cin>>a[i];
        Ni[i]=1+n-1-a[i];
    }
    set<int>ss;
    REP(i,0,n){
        ss.insert(Ni[i]);
    }
    vi NN(ss.begin(),ss.end());
    // deb(NN);
    for(int i=0;i<Ni.size();i++){
        aa[Ni[i]]++;
    }
    for(int i=0;i<NN.size();i++){
        // deb(i);
        // deb(NN[i]);
        // deb(aa[NN[i]]);
        if(aa[NN[i]]%NN[i]!=0){
            cout<<"No\n";
            return 0;
        }
    }
    cout<<"Yes\n";



return 0;
}