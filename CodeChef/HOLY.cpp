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
    int n, k;
    cin>>n>>k;
    vi a(n);
    REP(i,0,n){
        cin>>a[i];
    }
    // int l=0, r=0;
    // int ans=abs(a[0]-k);
    // int cur=a[0];
    // while(r<n){
    //     if(cur<k){
    //         ans=min(ans,abs(cur-k));
    //         r++;
    //         if(r<n){
    //             cur+=a[r];
    //         }
    //     }
    //     else{
    //         ans=min(ans,abs(cur-k));
    //         l++;
    //         if(l>r){
    //             r=l;
    //             if(r<n)
    //                 cur=a[l];
    //         }
    //         else{
    //             cur-=a[l-1];
    //         }
    //     }
    // }
    // ans=min(ans,abs(cur-k));
    // if(true){
    //     ans=min(ans,k);
    // }
    // cout<<ans<<"\n";
    vi par(n);
    par[0]=a[0];
    for(int i=1;i<n;i++){
        par[i]=a[i]+par[i-1];
    }
    for(int i=0;i<n;i++){
        int tar;
        if(i==0){
            tar=k;
        }
        else{
            tar=k+par[i-1];
        }

    }
    

    return 0;
}