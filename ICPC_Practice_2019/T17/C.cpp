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


vector<pair< pair<int, int> , pair<int, int>  > > diff;
int32_t main(){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int m;
    cin>>m;
    vi x(n+1);
    vi y(n+1);
    // vector<int>diff;
    REP(i,1,n+1){
        cin>>x[i]>>y[i];
        diff.PB({{x[i]-y[i],i},{x[i],y[i]}});
    }
    sort(diff.begin(),diff.end());
    vi preX(n+1,0);
    vi preY(n+1,0);
    vector<int>ans(n+1,0);
    for(int i=1; i<=n; i++){
        preX[i] = preX[i-1] + diff[i-1].second.first;
        preY[i] = preY[i-1] + diff[i-1].second.second;
    }
    for(int i=0; i<n; i++){
        int indx = diff[i].first.second;
        int xx = diff[i].second.first, yy = diff[i].second.second;
        ans[indx] += xx * (n - i - 1) + preY[n] - preY[i+1];
        ans[indx] += yy * i + preX[i];
    }
    while(m--){
        int xx, yy;
        cin >> xx >> yy;
        int score = min(x[xx] + y[yy], x[yy] + y[xx]);
        ans[xx] -= score;
        ans[yy] -= score;
    }
    
    for(int i=1; i<=n; i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";

    return 0;
}