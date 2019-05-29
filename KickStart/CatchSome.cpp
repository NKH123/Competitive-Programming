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

int dp[1005][1005];
int32_t main(){
	ios::sync_with_stdio(false);
    int t;
    cin>>t;
    vi p;
    vi a;
    vector<set<int> >ss;
    for(int T=1;T<=t;T++){
        int n, K;
        cin>>n>>K;
        p.resize(n);
        a.resize(n);
        ss.clear();
        ss.resize(n);
        REP(i,0,n){
            cin>>p[i];
        }
        REP(i,0,n){
            cin>>a[i];
        }
        deb(p);
        deb(a);
        for(int i=0;i<n;i++){
            dp[i][0]=p[i];
            ss[i].insert(i);
            // prev[i][0]=i;
        }
        deb(ss);
        vector<int>mini(n);
        for(int i=1;i<K;i++){
            for(int j=0;j<n;j++){
                dp[j][i]=1e18;
                 mini[j]=-1;
                for(int k=0;k<n;k++){
                    // if(j==k)continue;

                    if(ss[k].find(j)==ss[k].end()){
                        
                        int ans=dp[k][i-1];
                        if(a[k]==a[j]){
                            ans+=abs(p[k]-p[j]);
                        }
                        else{
                            ans+=(abs(p[k]+p[j]));
                        }
                        if(ans<dp[j][i]){
                            dp[j][i]=ans;
                            mini[j]=k;
                        }



                    }

                }
                // ss[j].insert(mini);
            }
            for(int j=0;j<n;j++){
                ss[j].insert(mini[j]);
            }
            deb(i);
            deb(ss);
        }
        int ans=1e18;
        deb(p);
        deb(a);
        deb("yo");
        for(int i=0;i<n;i++){
            for(int j=0;j<K;j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<"\n";
        }
        deb("\n");

        for(int i=0;i<n;i++){
            ans=min(ans,dp[i][K-1]);
        }
        cout<<"Case #"<<T<<": "<<ans<<"\n";


    }



	return 0;
}