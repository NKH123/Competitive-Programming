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

bool check(int N){
    int ans=0;
    while(N>=0){
        int sum=1;
        int temp=0;
        int tt=0;
        while(sum*3<=N){
            sum=sum*3;
            temp++;
        }
        N-=sum;
        // deb(temp);
        ans=ans^temp;
    }   
    return ans==0;

}

int32_t main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    set<int>S;
    for(int i=1;i<=100;i++){
        if(check(i)){
            S.insert(i);
        }
    }
    // check(7);
    // deb("here");
    // deb(S);
    while(t--){
        int x;
        cin>>x;
        int ans=*(S.lower_bound(x));
        cout<<ans<<"\n";
    }

    return 0;
}