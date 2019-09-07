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



int32_t main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    vi d;
    vi h;
    while(t--){
        int n, x;
        cin>>n>>x;
        d.clear();
        h.clear();
        int maxD=-1;
        int Dmax=0;
        REP(i,0,n){
            int D, H;
            cin>>D>>H;
            Dmax=max(Dmax,D);
            if(H>=D){
                continue;
            }
            else{
                maxD=max(maxD,D-H);
            }
            d.PB(D);
            h.PB(H);
            
        }
        x=x-Dmax;
        if(x<=0){
            cout<<1<<"\n";
            continue;
        }
        if(maxD==-1){
            cout<<-1<<"\n";
            continue;
        }
        int ans=1e18;
        
        for(int i=0;i<d.size();i++){
            int temp=x/(d[i]-h[i]);
            if((x%(d[i]-h[i]))){
                temp++;
            }
            ans=min(ans,temp);
        }
        ans++;
        cout<<ans<<"\n";



}



return 0;
}