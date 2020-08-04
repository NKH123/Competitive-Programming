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

#define // deb(x) cerr << #x << " = " << x << endl;
int ANS = 0;
int power(int x, int y){
    if(y==0){
        return 1LL;
    }
    else{
        int ans = power(x, y/2);
        ans= (ans*ans)%mod;
        if(y%2==1){
            ans=(ans*x)%mod;
        }
        return ans;
    }
}
int fact[100005];
int nCr(int n, int r){
    int N = fact[n];
    int D = (fact[n-r]*fact[r])%mod;
    D = power(D, mod-2);
    int ans = (N*D)%mod;
    return ans;
}
int n;
int k;
string s;
vector<int>AA;
void fun(int I){
    if(I == n){
        int val =0;
        int mul =1;
        int no =0;
        int yes1 = 0;
        for(int i=(int)AA.size()-1;i>=0;i--){
            if(AA[i] == 0){
                no++;
            }
            else{
                yes1=1;
                break;
            }
        }
        if(yes1==1 && no==k){
            // deb(AA);
            ANS++;
        }
        
    }
    else{
        AA.PB(s[I]-'0');
        fun(I+1);
        AA.pop_back();
        fun(I+1);
    }
}
int32_t main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    fact[1]=1;
    fact[0]=1;
    for(int i=2;i<(100005);i++){
        fact[i]=(i*fact[i-1])%mod;
    }
    vi count;
    while(t--){
        
        cin>>n;
        cin>>k;
        cin>>s;
        count.clear();
        count.resize(n);
        if(s[n-1]=='0'){
            count[n-1]=1;
        }
        for(int i=n-2;i>=0;i--){
            count[i]=count[i+1];
            if(s[i]=='0'){
                count[i]++;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                int left=i;
                int right=count[i];
                int ltemp = power(2, left);
                int rtemp = 0;
                if(k<=count[i]){
                    rtemp=nCr(count[i],k);
                }
                ans=(ans + ((ltemp%mod)*(rtemp%mod))%mod)%mod;
            }
        }
        // deb("here");
        // fun(0);
        // deb(ANS);
        // deb(ans);
        // assert(ANS ==ans);
        cout<<ans<<"\n";
    }

    return 0;
}