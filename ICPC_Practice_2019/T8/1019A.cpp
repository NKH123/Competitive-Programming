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



    vi p;
    vi c;
     int n, m;
    vector<pair<int, int> >pc;
    vi votes;
    bool comp(pi A, pi B){
        return A.F<B.F;
    }
    bool check(){
        int mine=votes[1];
        for(int i=2;i<=m;i++){
            if(mine<=votes[m]){
                return false;
            }
        }
        return true;
    }
int32_t main(){
    ios::sync_with_stdio(false);

   
    cin>>n>>m;
    p.clear();
    votes.resize(m+1);
    p.resize(n);
    c.clear();
    c.resize(n);
    REP(i,0,n){
        int A, B;
        cin>>A>>B;
        pc.PB({A,B});
        votes[A]++;
        // cin>>p[i]>>c[i];
    }
    int ans=0;
    sort(pc.begin(),pc.end(),comp);
    int I=0;
    while(!check()){
        while(pc[I].F==1){
            I++;
        }
        ans+=(pc[I].S);
        votes[pc[I].F]--;
        votes[1]++;
        pc[I].F=1;

    }
    cout<<ans<<"\n";


    return 0;
}