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


vector<vector<int> >a;
// int dp1[105][105];
// int dp2[105][105];
map<pair<int, int>,int>dp1;
map<pair<int, int>,int>dp2;
int32_t main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;

    while(t--){
        int m, n;
        cin>>m>>n;
        a.clear();
        // memset(dp1,0,sizeof(dp1));
        // memset(dp2,0,sizeof(dp2));
        dp1.clear();
        dp2.clear();
        a.resize(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cin>>a[i][j];
            }
        }
        // deb(a);
        int ans=-(1e18);
        //preprocess
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int diff=i-j;
                int summ=i+j;
                dp1[{i,diff}]=(a[i][j]+dp1[{i-1,diff}]);
                dp2[{i,summ}]=(a[i][j]+dp2[{i-1,summ}]);
            }
        }
        // deb(dp1);
        // deb(dp2);
        // exit(0);
        for(int len=2;len<=min(n,m);len++){
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){

                    int x1=i;
                    int x2=x1+len-1;
                    int y1=j;
                    int y2=y1+len-1;
                    int sum=0;
                    // deb(len);
                    // cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<"\n";
                    if(x1>(m-1) || x2>(m-1) || y1> (n-1) || y2>(n-1)){
                        continue;
                    }
                    int diff=x1-y1;
                    int summ=x2+y1;
                    // deb(diff);
                    // deb(summ);
                    //get sum x1 y1 to x2 y2
                    sum=dp1[{x2,diff}]-dp1[{x1-1,diff}];
                    // deb(dp1[{x2,diff}]-dp1[{x1-1,diff}]);
                    //get sum from x2 y1 to x1 y2
                    // deb(sum);
                    sum+=(dp2[{x2,summ}]-dp2[{x1-1,summ}]);
                    // deb(dp2[{x2,summ}]-dp2[{x1-1,summ}]);
                    // deb(sum);
                    if((len%2)==1){
                        int xmid=(x1+x2)/2;
                        int ymid=(y1+y2)/2;
                        sum-=a[xmid][ymid];
                    }
                    // deb(sum);
                    ans=max(sum,ans);

                }
            }
        }
        cout<<ans<<"\n";

    }



    return 0;
}