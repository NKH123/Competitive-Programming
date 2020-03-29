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


vector<vector<int> >c;
int32_t main(){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<vector<int> >a(n);
    vector<vector<int> >b;
    b.clear();
    int B=0;
    
    c.clear();
    vi G(1000006);
    REP(i,0,n){
        int x;
        cin>>x;
        a[i].resize(x);
        int Gg=-1;
        int f=0;
        int ele;
        // deb(i);
        REP(j,0,x){
            cin>>a[i][j];
            if(j==0){
                ele=a[i][j];
            }
            else{
                if(a[i][j]>ele){
                    f=1;
                }
                else{
                    ele=a[i][j];
                }
            }
            Gg=max(Gg,a[i][j]);
        }
        if(f==1){
            // deb(a[i]);
            // b.PB(a[i]);
            B++;
        }
        else{
            // deb(a[i]);
            c.PB(a[i]);
        }
        if(f==0){
            // deb("ehere");
            G[Gg]++;
        }
    }
    int ans=0;
    // deb(a);
    // deb(b);
    // deb(c);
    // deb(B);
    // deb(c);
    // deb(G);
    REP(i,1,G.size()){
        G[i]+=G[i-1];
    }
    // deb(G[100000]);
    // REP(i,0,100){
    //     deb(i);
    //     deb(G[i]);
    // }
    REP(i,0,c.size()){
        // int x;
        // cin>>x;
        // a[i].resize(x);
        // deb(i);
        // deb(c[i]);
        int Ss=1e18;
        REP(j,0,c[i].size()){
            // cin>>a[i][j];
            Ss=min(Ss,c[i][j]);
        }
        // G[Gg]++;
        // for(int j=Ss+1;j<10;j++){
        //     ans+=G[j];
        // }
        // deb(Ss);

        // deb((G[1000005]-G[Ss]));
        // deb(i);
        // deb(c[i]);
        // deb(Ss);
        // deb((G[1000005]-G[Ss]));
        ans+=(G[1000005]-G[Ss]);
    }
    // deb(ans);
    // REP(i,0,b.size()){
    //     ans+=(2*(c.size()));
    // }
    // deb(c);
    // REP(i,0,100){
    //     deb(i);
    //     deb(G[i]);
    // }
    // deb((G[1000005]));
    ans+=(B*(2*c.size()));
    ans+=(B*B);
    cout<<ans<<"\n";


    return 0;
}