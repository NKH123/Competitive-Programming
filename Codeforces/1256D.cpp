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
    int q;
    cin>>q;
    vi ans;
    vi b;
    vi nn;
    while(q--){
        int n, k;
        cin>>n>>k;
        string s;
        cin>>s;
        int rem=k;
        b.clear();
        b.resize(n);
        nn.clear();
        nn.resize(n);
        for(int i=0;i<n;i++){
            if(i==0){
                if(s[i]=='0'){
                    nn[0]=0;
                }
                else{
                    nn[0]=1;
                }
            }
            else{
                if(s[i]=='0'){
                    nn[i]=nn[i-1];
                }
                else{
                    nn[i]=nn[i-1]+1;
                }
            }
        }
        int pos=-1;
        int noOnes=0;
        int par=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                b[i]=1e18;
                pos=i;
                if(rem>=noOnes){
                    rem-=noOnes;
                    b[i]=0;

                }
                else{
                    b[i]=noOnes-rem;

                    par=noOnes-rem;
                    break;
                }
            }
            else{
                noOnes++;
            }
        }
        // deb(b);
        // deb(s);
        // deb(pos);
        ans.clear();
        if(pos==-1){
            cout<<s<<"\n";
        }
        else{
            for(int i=0;i<pos;i++){
                if(s[i]=='0'){
                    ans.PB(0);
                }
            }
            int total=nn[pos];
            for(int i=0;i<par;i++){
                ans.PB(1);
            }
            ans.PB(0);
            for(int i=0;i<(total-par);i++){
                ans.PB(1);
            }
            for(int i=pos+1;i<n;i++){
                ans.PB((s[i]-'0'));
            }
            for(int i=0;i<n;i++){
                cout<<ans[i];
            }
            cout<<"\n";
        }
    }

    return 0;
}