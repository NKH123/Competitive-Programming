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
    int n;
    cin>>n;
    vi a(n);
    REP(i,0,n){
        cin>>a[i];
    }
    vi par(n);
    int ans=0;
    REP(i,0,n){
        if(i==0){
            if(a[i]==1)
            par[i]=a[i];
        }
        else{
            if(par[i]==1){
                par[i]=par[i-1]+1;
            }
            else{
                par[i]=par[i-1];
            }
        }
        ans=max(ans,par[i]);
    }
    
    for(int i=0;i<n;i++){
        if(a[i]==2){
            int cons=0;
            int amxi=0;
            for(int j=0;j<i;j++){
                if(cons==0){
                    if(a[i]==2){
                        cons++;
                    }
                    else{

                    }
                }
                else{
                    if(a[i]==2){
                        cons++;
                    }
                    else{
                        cons=0;
                    }

                }
                amxi=max(amxi,cons);
            }
            par[i]=par[i]+amxi;
        }
    }

    for(int i=0;i<n;i++){
        ans=max(ans,par[i]);
    }
    cout<<ans<<"\n";

    return 0;
}