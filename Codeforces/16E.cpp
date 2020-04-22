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

int n;

double tab[27][27];

double dp[19][300007];

double wyn;


int32_t main(){
    ios::sync_with_stdio(false);
    scanf("%d", &n);
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            scanf("%lf", &tab[i][j]);
        }
    }

    for(int I=0;I<n;I++){
        memset(dp,0,sizeof(dp));
        dp[I][(1<<I)]=1.0;
        for (int mask=1; mask<(1<<n); mask++)
        {
            if(__builtin_popcount(mask)==1){
                continue;
            }
            for (int j=0; j<n; j++)
        {   //j must me set
            if ((mask&(1<<j))==0)
                continue;
            double s=0;
            for (int k=0; k<n; k++)
            {   //k must also be set and is different from j
                if ((mask&(1<<k))==0 || k==j)
                    continue;
                dp[j][mask]=max(dp[j][mask], dp[k][mask^(1<<j)]*tab[k][j]+dp[j][mask^(1<<k)]*tab[j][k]);
                //printf("%d %d    %lf %lf\n", j, k, dp[k][i^(1<<j)], tab[j][k]);
            }
            //printf("%d %d   %lf\n", j, i, dp[j][i]);
        }
    }
    for (int i=0; i<n; i++)
        wyn=max(wyn, dp[i][(1<<n)-1]);
    printf("%.9lf ", wyn);
}
return 0;

return 0;
}