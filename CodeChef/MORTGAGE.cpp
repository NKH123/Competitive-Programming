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
int n, m, t;
vector<pair<int, int> >sp;
bool comp(pi A, pi B){
	return A.S<B.S;
}
long double modpow(long double a, int b){
    long double ret=1.0;
    while(b){
        if (b%2) ret = ret*a;
        b/=2;
        a*=a;
    }
    return ret;
}
vector<double> ass(n);
bool check(double amt){
		// deb(amt);
		ass.clear();
		ass.resize(n);
	
	int i=0;
	while(amt>0){
		ass[i]=min(amt, (double)sp[i].F);
		amt-=ass[i];
		i++;
	}
	// deb(ass);
	int II=i-1;
	i=0;
	double T=t;

	while(i<=m){
		T=t;
		
		for(int I=II;I>=0;I--){
			double rem;
			rem=min(T,ass[I]);
			ass[I]-=rem;
			T-=rem;
			if(T<=(0)){
				break;
			}
		}

		// deb(i);
		// deb(ass);
		for(int I=II;I>=0;I--){
			ass[I]=ass[I]*modpow(1+sp[I].S*1.0/1000000,i+1);
		}
		
		// deb(ass);
		i++;
	}
	// deb(ass);
	for(int I=0;I<n;I++){
		if(ass[I]!=0){
			return false;
		}
	}
	return true;

}
int32_t main(){
	ios::sync_with_stdio(false);

	cin>>n>>m>>t;
	vi s;
	vi p;
	sp.resize(n);
	int maxi=0;
	REP(i,0,n){
		cin>>sp[i].F;
		maxi+=sp[i].F;
	}
	REP(i,0,n){
		cin>>sp[i].S;
	}
	sort(sp.begin(),sp.end(),comp);
	double l=0, r=maxi;
	double ans=0;
	// deb(ans);
	int itr=0;
	while(l<=r && itr<=100){
		double mid=((l+r)/2);
		// deb(mid);
		if(check(mid)){
			// deb(mid);
			deb(mid);
			deb(l);
			deb(r);
			ans=mid;
			l=mid;
		}
		else{
			deb("no");
			deb(mid);
			r=mid;
		}
		// deb("********************************************************");
		itr++;
	}
	// deb(ans);
	printf("%.9f\n",ans);
	deb(check(5.7272));
	return 0;
}