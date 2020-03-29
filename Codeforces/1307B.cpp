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

bool comp(int a, int b){
    return a>b;
}

int32_t main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    vi a;
    while(t--){
        int n, x;
        cin>>n>>x;
        a.clear();
        a.resize(n);
        int f=0;
        REP(i,0,n){
            cin>>a[i];
            if(a[i]==x){
                f=1;
            }
        }
        if(f==1){
            cout<<1<<"\n";
        }
        else{
            sort(a.begin(),a.end(),comp);
            if(a[0]>x){
                cout<<2<<"\n";
            }
            else{
                int ans=x/a[0];
                // ans+=2;
                // if(a.size()>=2){
                //     if(a[0]+a[1]>=(((x/a[0]>0)?a[0]:0)+x%a[0])){
                //         ans--;
                //     }
                // }
                if(x%a[0]!=0)
                if(ans>0){
                    ans--;
                    ans+=2;

                }
                else{
                    ans+=2;
                }
                cout<<ans<<"\n";
            }
        }
    }

    return 0;
}