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
#define print(x) cout<<#x<<" is "; for(int i=0;i<x.size();i++){cout<<x[i]<<" ";}cout<<"\n"
#define llp 1000000007
#define mod 1000000007

/// ********* debug template by Bidhan Roy *********

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

bool comp(int A,int B){
	return A>B;
}
void pr(string s,int n=0){
	for(int i=0;i<n;i++){
		cout<<"****";
	}
	cout<<s;
}
int main(){
	ios::sync_with_stdio(false);

	int t;
	cin>>t;
	
	vl a(26);
	while(t--){
		a.clear();
		a.resize(26);
		string s;
		set<char>ss;
		ss.clear();
		cin>>s;
		for(auto g:s){
			char aa=g;
			a[g-'A']++;
			ss.insert(aa);
		}
		
		/*trace(s.size());
		cout<<"Before dis="<<dis<<"\n";
		int red=0;*/
		/*while(!((s.size()%dis)==0)){
			dis--;
			red++;
		}
		trace(dis);
		trace(red);
		sort(a.begin(),a.end(),comp);
		print(a);
		ll ele=s.size()/dis;
		trace(ele);
		ll ans=0;
		ll ans1=s.size()-a[0];
		for(int i=0;i<dis;i++){
			if(a[i]>ele){
				ans+=a[i]-ele;
			}
		}
		for(int i=dis;i<(dis+red);i++){
			ans+=a[i];
		}
		ans=min(ans,ans1);*/
		//deb(ss);
		ll dis=ss.size();
		ll ans=1L<<60;
		ll red;
		sort(a.begin(),a.end(),comp);
		//deb(a);
		for(int i=min(26,(int)s.size());i>=1;i--){
		//	deb(i);
			ll Ans=0;
			if((s.size()%i)!=0)continue;
		//	deb("It divides");
			//red=dis-i;
			
			ll ele=s.size()/i;
		//	deb(ele);
			for(int j=0;j<i;j++){
		//		deb(j);
				if(a[j]>ele){
		//			cout<<"Inside condition true";
					Ans+=a[j]-ele;
				}
			}
			for(int j=i;j<26;j++){
				Ans+=a[j];
			}
			/*for(int j=i;j<(i+red);j++){
				Ans+=a[j];
			}*/
		//	deb(Ans);
			ans=min(Ans,ans);
		//	deb(ans);
		}
		cout<<ans<<"\n";

	}


	return 0;
}