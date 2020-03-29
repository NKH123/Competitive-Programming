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



int32_t main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int a, b;
        cin>>a>>b;
        int ans=0;
        int st=1;
        int small=1e18;
        // while(a!=b){
        //     deb(a);
        //     deb(b);
        //     deb(small);
        //     small=min(small,abs(a-b));
        //     if(abs(a-b)==1){
        //         ans+=2;
        //         break;
        //     }
        //     if(a<b)
        //     while(a<b){
        //         a+=st;
        //         st++;
        //         ans++;
        //     }
        //     else
        //         {  
        //          while(b<a){
        //             b+=st;
        //             st++;
        //             ans++;
        //         }
        //     }
        //     // ans++;
        //     // st++;
        // }
        int l=0, r=1e9;
        if(a>b){
            swap(a,b);
        }
        int ini=0;
        while(l<=r){
            int mid=(l+r)/2;
            if(a+(mid*(mid+1))/2>b){
                r=mid-1;
            }
            else{
                ini=mid;
                l=mid+1;
            }
        }
        if(abs(a+(ini*(ini+1))/2-b)>abs(a+((ini+1)*(ini+2))/2-b)){
            ini++;
        }
        a+=(ini*(ini+1))/2;
        ans+=(ini);
        ans+=(2*abs(b-a));
        cout<<ans<<"\n";
    }

    return 0;
}