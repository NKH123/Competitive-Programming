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



int dp[51][2187];

void get(int val,int*arr,int siz)
{
	for(int i=0;i<siz;i++)
		arr[i]=val%3,
	val/=3;
}


signed main()
{
	ios_base::sync_with_stdio(0);
	// cin.tie(0);ss
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		if(n<m)
			swap(n,m);
		int pw=1;
		for(int i=1;i<=m;i++)
			pw*=3;
		for(int i=0;i<=n;i++)
			for(int j=0;j<pw;j++)
				dp[i][j]=-100;
			dp[0][pw-1]=0;
			int ans=0;
			for(int i=1;i<=n;i++)
				for(int j=0;j<pw;j++)
				{
					if(dp[i-1][j]<0)
						continue;
					int a[m];
					get(j,a,m);
					for(int k=0;k<pw;k++)
					{
						int b[m];
						get(k,b,m);
						bool ok=true;
						for(int i=0;i<m;i++)
						{
							if(a[i]==1&&b[i]!=0)
								ok=false;
							if(b[i]==1&&(a[i]==0||(i>0&&b[i-1]==0)||(i<m-1&&b[i+1]==0)))
								ok=false;
							if(b[i]==2&&a[i]!=0&&(i==0||b[i-1]!=0)&&(i==m-1||b[i+1]!=0))
								ok=false;
						}
						if(ok)
						{
							int cnt=0;
							for(int t=0;t<m;t++)
								if(b[t])
									cnt++;
//                    cout<<i<<" "<<str(j,m)<<" "<<str(k,m)<<" -> "<<dp[i-1][j]<<" "<<cnt<<"\n";
								dp[i][k]=max(dp[i][k],dp[i-1][j]+cnt);
								bool is1=false;
								for(int t=0;t<m;t++)
									if(b[t]==1)
										is1=true;
									if(!is1)
										ans=max(ans,dp[i][k]);
								}
							}
						}
						cout<<ans<<"\n";
					}
					return 0;
				}