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



int32_t main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    vector<vector<int> >a;
    vector<set<int> >row;
    vector<set<int> >col;
    for(int T=1;T<=t;T++){
        int n;
        cin>>n;
        a.clear();
        a.resize(n);
        REP(i,0,n){
            a[i].resize(n);
        }
        int trace=0;
        row.clear();
        col.clear();
        row.resize(n);
        col.resize(n);
        REP(i,0,n){
            REP(j,0,n){
                cin>>a[i][j];
                if(i==j){
                    trace+=a[i][j];
                }
                row[i].insert(a[i][j]);
                col[j].insert(a[i][j]);
            }
        }
        int R=0;
        int C=0;
        for(int i=0;i<n;i++){
            if(row[i].size()<n){
                R++;
            }
            if(col[i].size()<n){
                C++;
            }
        }
        cout<<"Case #"<<T<<": "<<trace<<" "<<R<<" "<<C<<" "<<"\n";


    }

    return 0;
}