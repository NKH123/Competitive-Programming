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
    int q;
    cin>>q;
    while(q--){
        int n;
        cin>>n;
        int f[4];
        int Xl=-(100000), Xr=100000, Yd=-100000, Yu=100000;
        int F=1;
        for(int i=0;i<n;i++){
            int x, y;
            cin>>x>>y;
            for(int j=0;j<4;j++){
                cin>>f[j];
            }
            int xl=-(100000), xr=100000, yd=-100000, yu=100000;
            if(f[0]==1){

            }
            else{
                xl=x;
            }
            if(f[1]==1){

            }
            else{
               yu=y; 
            }
            if(f[2]==1){

            }
            else{
                xr=x;
            }
            if(f[3]==1){

            }
            else{
                yd=y;
            }
            Xl=max(Xl,xl);
            Xr=min(Xr,xr);
            Yu=min(Yu,yu);
            Yd=max(Yd,yd);
            if(Xl>Xr || Yd>Yu){
                // cout<<0<<"\n";
                F=0;
                // break;
            }
        }
        if(F==0){
            cout<<0<<"\n";
            continue;
        }
        cout<<1<<" ";
        cout<<Xl<<" "<<Yd<<"\n";
    }    



    return 0;
}