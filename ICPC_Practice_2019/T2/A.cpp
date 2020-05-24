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
    // int r, g, b;
    // cin>>r>>g>>b;
    int Ans=0;
    vi a(3);
    int ans=0;
    REP(i,0,3){
        cin>>a[i];
        // ans+=(a[i]/3);
        // a[i]=a[i]%3;
    }
    vi b;
    b=a;
    REP(i,0,3){
        // cin>>a[i];
        ans+=(a[i]/3);
        a[i]=a[i]%3;
    }
    sort(a.begin(),a.end());
    // int ans=a[0];

    ans+=a[0];
    // cout<<ans<<"\n";
    Ans=max(Ans,ans);
    a=b;
    ans=1;
    int f=1;
    REP(i,0,3){
        if(a[i]>=1){
            a[i]--;
        }
        else{
            f=0;
        }
    }
    if(f==1){
        REP(i,0,3){
        // cin>>a[i];
            ans+=(a[i]/3);
            a[i]=a[i]%3;
        }
        sort(a.begin(),a.end());
    // int ans=a[0];

        ans+=a[0];
    // cout<<ans<<"\n";
        Ans=max(Ans,ans);
    }
    a=b;
    ans=2;
    f=1;
    REP(i,0,3){
        if(a[i]>=2){
            a[i]=a[i]-2;
        }
        else{
            f=0;
        }
    }
    if(f==1){
        REP(i,0,3){
        // cin>>a[i];
            ans+=(a[i]/3);
            a[i]=a[i]%3;
        }
        sort(a.begin(),a.end());
    // int ans=a[0];

        ans+=a[0];
    // cout<<ans<<"\n";
        Ans=max(Ans,ans);
    }

    cout<<Ans<<"\n";




    return 0;
}