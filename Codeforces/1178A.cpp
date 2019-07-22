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
    int n;
    cin>>n;
    // vi a(n-1);
    vector<pair<int,int> >a(n-1);
    int A;
    int tot=0;
    REP(i,0,n){
        if(i==0){
            cin>>A;
            tot+=A;
        }
        else{
            cin>>a[i-1].F;
            a[i-1].S=i+1;
            tot+=a[i-1].F;
        }
    }
    sort(a.begin(),a.end());
    // deb(a);
    vi ans;
    ans.PB(1);

    int sum=0;
    sum+=A;
    for(int i=0;i<(n-1);i++){
        if(2*a[i].F<=A){
            ans.PB(a[i].S);
            sum+=a[i].F;
        }
    }
    if(2*sum<=(tot)){
        cout<<0<<"\n";
    }
    else{
        cout<<ans.size()<<"\n";
        REP(i,0,ans.size()){
            cout<<ans[i]<<" ";
        }
        cout<<"\n";
    }





    return 0;
}