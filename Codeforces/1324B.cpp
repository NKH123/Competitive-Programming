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

vector<vector<int> >l;
vector<vector<int> >r;

int32_t main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    vi a;
    set<int>S;
    while(t--){
        int n;
        cin>>n;
        // a.clear();
        // a.resize(n);
        // l.clear();
        // r.clear();
        // l.resize(n,vector<int>(n+1));
        // r.resize(n,vector<int>(n+1));
        // REP(i,0,n){
        //     cin>>a[i];
        // }
        // // memset(l,0,sizeof(l));
        // // memset(r,0,sizeof(r));
        // for(int i=0;i<n;i++){
        //     if(i==0)
        //         l[i][a[i]]++;
        //     else{
        //         for(int j=1;j<=n;j++){
        //             l[i][j]=l[i-1][j];
        //         }
        //         l[i][a[i]]=l[i-1][a[i]]+1;

        //     }

        // }
        // for(int i=n-1;i>=0;i--){
        //     if(i==n-1)
        //         r[i][a[i]]++;
        //     else{
        //         for(int j=1;j<=n;j++){
        //             r[i][j]=r[i+1][j];
        //         }
        //         r[i][a[i]]=r[i+1][a[i]]+1;
        //     }

        // }
        int f=0;
        // deb(l);
        // deb(r);
        // for(int i=1;i<n-1;i++){
        //     for(int j=1;j<=n;j++){
        //         if(l[i-1][j]>0 && r[i+1][j]>0){
        //             f=1;
        //         }
        //     }
        // }
        // int ct[n+1];

        // memset(ct,0,sizeof(ct));
        a.resize(n);
        REP(i,0,n){
            cin>>a[i];
            // ct[a[i]]++;
        }
        S.clear();
        for(int i=2;i<n;i++){
            S.insert(a[i-2]);
            if(S.find(a[i])!=S.end()){
                f=1;
            }
        }


        if(f==1){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }


    }

    return 0;
}
OPEN SERVICE BROKER
