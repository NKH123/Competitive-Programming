#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <b; i++)
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef pair<int,int> pi;
#define trace(x) cout<<#x<<"="<<x<<"\n";
#define llp 1000000007
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


int main(){
	ios::sync_with_stdio(false);

    int t;
    cin>>t;
    vi a(100005);
    vi c(100005);
    vi par(100005);
    vi par1(100005);
    vi L,R;
    while(t--){
        a.clear();
        a.resize(100005);
        c.clear();
        c.resize(100005);
        par.clear();
        par.resize(100005);
        par1.clear();
        par1.resize(100005);
        int n,k;
        cin>>n;
        cin>>k;
        L.resize(n);
        R.resize(n);
        int N=100001;
        REP(i,0,n){
            int l, r;
            cin>>l>>r;
            L[i]=l;
            R[i]=r;
            a[l]++;
            a[r+1]--;
        }
        REP(i,0,N){
            if(i==0 || i==1){
                c[i]=a[i];
            }
            else{
                c[i]=c[i-1]+a[i];
            }
        }
       // ll ans=0;
        REP(i,1,N){
            par[i]=par[i-1];
            par1[i]=par1[i-1];
            if(c[i]==k){
              //  ans++;
                par1[i]+=1;
            }
            else if(c[i]==(k+1)){
                par[i]+=1;
            }
            
        }
        ll ans=par1[100000]-par1[0];
        
        ll Ans=-1;
        REP(i,0,n){
            int l=L[i],r=R[i];
            Ans=max(Ans,ans+(par[r]-par[l-1]-(par1[r]-par1[l-1])));
           
        }
        cout<<Ans<<"\n";
    }


    return 0;
}