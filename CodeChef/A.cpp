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


int exam(vector<int> v) {
    vector<int>par(v.size());
    par.clear();
    par[0]=v[0];
    for(int i=1;i<v.size();i++){
        par[i]=par[i-1]+v[i];
    }
    int n=par.size();
    deb(par);
    for(int i=0;i<par.size();i++){
        int my=0, fr=0;
        if(i==0){
            my=0;
            fr=par[n-1]-(n-par[n-1]);
        }
        else{
            my=par[i-1]-(i-par[i-1]);
            fr=par[n-1]-par[i-1]-(n-i+1-par[n-1]+par[i-1]);
        }
        // cout<<i<<"\n";
        // cout<<my<<" "<<par<<"\n";
        // cout<<"****\n";
        deb(i);
        deb(my);
        deb(fr);
        // printf("%d\n",i);
        // printf("%d %d\n",my,par);
        // printf("*****\n");
        if(my>fr){
            if(i!=0)
            return i;
        }
    }
    return n;
}
int32_t main(){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    vi v;
    v.resize(n);
    REP(i,0,n){
        cin>>v[i];
    }
    deb(exam(v));

    return 0;
}