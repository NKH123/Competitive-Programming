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
    vi a;
    int INF=1e18;
    while(t--){
        int n;
        cin>>n;
        a.resize(n);
        REP(i,0,n){
            cin>>a[i];
        }
        string s;
        cin>>s;
        int L=0, R=INF;
        if(a[n-1]!=-1){
            L=a[n-1];
            R=a[n-1];
        }
        int f=1;
        for(int i=n-2;i>=0;i--){

            if(a[i]==-1){
                if(s[i]=='='){
                    
                }
                if(s[i]=='<'){
                    L=0;
                    R=R-1;
                    
                }
                if(s[i]=='>'){
                    L=L+1;
                    R=INF;
                }
                if(L>R || R<0){
                    f=0;
                }   
            }
            else {
                if(s[i]=='='){
                    if(a[i]>=L && a[i]<=R){

                    }
                    else{
                        f=0;
                    }
                }
                if(s[i]=='<'){
                    if(a[i]<R){

                    }
                    else{
                        f=0;
                    }
                    
                }
                if(s[i]=='>'){
                    if(a[i]>L){

                    }
                    else{
                        f=0;
                    }
                }
                L=a[i];
                R=a[i];
            }
            if(f==0){
                break;
            }
        }
        if(f==0){
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n";
        }


}
ACcio_glory
ACcio_Glory
accio_glory





return 0;
}