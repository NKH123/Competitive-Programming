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

struct comp{
    bool operator()(const pair<int, int>& A, const pair<int, int>& B ){
        if((A.S-A.F)!=(B.S-B.F)){
            return (A.S-A.F)>(B.S-B.F);
        }
        else{
            return A.F<B.F;
        }
    }
};

int32_t main(){
    ios::sync_with_stdio(false);
    set<pair<int, int>, comp>S;
    int t;
    cin>>t;
    vi a;
    while(t--){
        a.clear();
        int n;
        cin>>n;
        a.resize(n);
        S.clear();
        S.insert({0,n-1});
        int I=1;
        while(S.size()!=0){
            auto G=*(S.begin());
            int ind=(G.first+G.second)/2;
            S.erase(S.begin());
            a[ind]=I;
            I++;
            if(G.F!=G.S){
                int l=G.F;
                int r=ind-1;
                if(l<=r)
                S.insert({l,r});
                r=G.S;
                l=ind+1;
                if(l<=r)
                S.insert({l,r});
            }
        }
        for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}