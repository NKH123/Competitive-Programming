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

bool comp(pi A, pi B){
    // if(A.F==B.F){
    //     return A.S>B.S;
    // }
    // else{
    //     A.F<B.F;
    // }
    return A.F<B.F;
}

int32_t main(){
    ios::sync_with_stdio(false);
    int n, m;
    cin>>n>>m;
    vector<pair<int, int> >AB;
    for(int i=0;i<n;i++){
        int A, B;
        cin>>A>>B;
        AB.PB({A,B});
    }
    sort(AB.begin(),AB.end(),comp);
    priority_queue<int>pq;
    int ans=0;
    int I=0;
    // deb(AB);
    for(int i=1;i<=m;i++){
        // deb(i);
        // deb(I);
        while(I<n){
            // deb("I");
            // deb(I);
            if(AB[I].F>i){
                break;
            }
            else{
                pq.push(AB[I].S);
                I++;
            }
        }
        if(pq.size()!=0){
        auto T=pq.top();
        ans+=T;
        pq.pop();
        }
        
    }
    cout<<ans<<"\n";


    return 0;
}