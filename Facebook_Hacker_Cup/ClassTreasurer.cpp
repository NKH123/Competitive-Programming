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

int power(int a, int b){
    if(b==0){
        return 1;
    }
    else{
        int ans=power(a,b/2);
        ans=(ans*ans)%mod;
        if((b%2)==1){
            ans=((a%mod)*(ans))%mod;
        }
        return ans;
    }
}

int32_t main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    int T=t;
    vector<int>mark;
    while(t--){
        int n;
        cin>>n;
        int k;
        cin>>k;
        string s;
        cin>>s;
        vi a;
        a.clear();
        a.resize(s.size());
        if(s[0]=='B'){
            a[0]=1;
        }
        for(int i=1;i<s.size();i++){
            a[i]=a[i-1];
            if(s[i]=='B'){
                a[i]++;
            }
        }
        int l, r=-1;
        deb(a);
        mark.clear();
        mark.assign(n,0);
        for(int i=0;i<n;i++){
            if(s[i]=='A')continue;
            r=max(r,i+k);
            while(r<n){
                int b=a[r];
                if(i!=0){
                    b-=a[i-1];
                }
                int L=r-i+1;
                if((2*b-L)>k){
                    mark[i]=1;
                    break;
                }
                r++;
            }
            deb(r);
            if(r==n){
                r=-1;
            }

        }
        deb(mark);
        int ans=0;
        for(int i=0;i<n;i++){
            if(mark[i])
            ans=(ans+power(2,i+1))%mod;
        }
        cout<<ans<<"\n";
    }



    return 0;
}