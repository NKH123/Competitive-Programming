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
vector<char>ans;
int x, y;
int mx, my;
int st=0;
int check(int x, int y){
	int f=1;
	int l=0;
	for(int i=st;i<60;i++){
		if((x&(1LL<<i))!=0 || ((y&(1LL<<i)))!=0){
			// f=0;
			l=max(l,i);
		}
	}
	//deb(l);
	for(int i=st;i<=l;i++){
		if((x&(1LL<<i))!=0 && ((y&(1LL<<i)))!=0){
			f=0;
			st=i;

		}
		if((x&(1LL<<i))==0 && ((y&(1LL<<i)))==0){
			f=-1;
			st=i;
		}
	}
	return f;
}
bool can(int x, int y){
	int f=0;
	for(int i=0;i<60;i++){
		if((x&(1LL<<i))!=0 && ((y&(1LL<<i)))!=0){
			f=1;

		}
		else if((((x&(1LL<<i))!=0 && ((y&(1LL<<i)))==0) || ((x&(1LL<<i))==0 && ((y&(1LL<<i)))!=0)) &&(f==0)){
			return true;
		}
	}
	return false;
}
bool can1(int x, int y){
	int f=0;
	int l=0;
	for(int i=0;i<60;i++){
		if((x&(1LL<<i))!=0 || ((y&(1LL<<i)))!=0){
			// f=0;
			l=max(l,i);
		}
	}
	int ff=0;
	for(int i=0;i<=l;i++){
		if((x&(1LL<<i))==0 && ((y&(1LL<<i)))==0){
			f=1;

		}
		else if((((x&(1LL<<i))!=0 && ((y&(1LL<<i)))==0) || ((x&(1LL<<i))==0 && ((y&(1LL<<i)))!=0)) &&(f==0)){
			return true;
		}
	}
	return false;
}
void fix(){
	int f=0;
	for(int i=0;i<60;i++){
		if((x&(1LL<<i))!=0 && ((y&(1LL<<i)))!=0){
			f=1;

		}
		else if((((x&(1LL<<i))!=0 && ((y&(1LL<<i)))==0) || ((x&(1LL<<i))==0 && ((y&(1LL<<i)))!=0)) &&(f==0)){
			if((((x&(1LL<<i))!=0 && ((y&(1LL<<i)))==0))){
				x+=(1LL<<i);
				if(mx==1){
					ans[i]='W';
				}
				else{
					ans[i]='E';
				}
				return;
			}
			else if(((x&(1LL<<i))==0 && ((y&(1LL<<i)))!=0)){
				y+=(1LL<<i);
				if(my==1){
					ans[i]='S';
				}
				else{
					ans[i]='N';
				}
				return;
			}
		}
	}
	// return false;
}
void fix1(){
	int f=0;
	for(int i=0;i<60;i++){
		if((x&(1LL<<i))==0 && ((y&(1LL<<i)))==0){
			f=1;

		}
		else if((((x&(1LL<<i))!=0 && ((y&(1LL<<i)))==0) || ((x&(1LL<<i))==0 && ((y&(1LL<<i)))!=0)) &&(f==0)){
			if((((x&(1LL<<i))!=0 && ((y&(1LL<<i)))==0))){
				x+=(1LL<<(i+1));
				if(mx==1){
					ans[i]='W';
				}
				else{
					ans[i]='E';
				}
				return;
			}
			else if(((x&(1LL<<i))==0 && ((y&(1LL<<i)))!=0)){
				y+=(1LL<<(i+1));
				if(my==1){
					ans[i]='S';
				}
				else{
					ans[i]='N';
				}
				return;
			}
		}
	}
	// return false;
}

int32_t main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;

	for(int i=1;i<=t;i++){
		st=0;
		ans.clear();
		ans.resize(100,'#');
		cout<<"Case #"<<i<<": ";
		// int x, y;
		mx=1;
		my=1;
		cin>>x>>y;
		if(x<0){
			mx=-1;
		}
		if(y<0){
			my=-1;
		}
		x=abs(x);
		y=abs(y);
		// if(__builtin_popcount((x|y)+1)!=(1)){
		// 	////deb("not power of two");
		// 	cout<<"IMPOSSIBLE\n";
		// 	continue;
		// }
		

		int f=1;
		int ff;
		//deb(check(x,y));
		while((ff=check(x,y))!=1){
			//deb(ff);
			//deb("in check");
			//deb(ans);
			//deb(x);
			//deb(y);
			if(ff==0){
				if(can(x,y)){
					fix();
				//deb("11******after fix");
				//deb(x);
				//deb(y);
				//deb(ans);
				}
				else{
					f=0;
					//deb("11");
				//deb("cant");
					cout<<"IMPOSSIBLE\n";
					break;
				}
			}
			else{
				if(can1(x,y)){
					fix1();
					//deb("00******after fix");
				//deb(x);
				//deb(y);
				//deb(ans);
				}
				else{
					f=0;
					//deb("00");
				//deb("cant");
					cout<<"IMPOSSIBLE\n";
					break;
				}
			}
		}
		if(f==0){
			continue;
		}
		//deb(ans);
		for(int i=0;i<=60;i++){
			if ((x&(1LL<<i))==0 && ((y&(1LL<<i)))!=0){
				if(my==1){
					// cout<<"N";
					if(ans[i]=='#')
					ans[i]='N';
				}
				else{
					// cout<<"S";
					if(ans[i]=='#')
					ans[i]='S';
				}
			}
			if((x&(1LL<<i))!=0 && ((y&(1LL<<i)))==0){
				if(mx==1){
					// cout<<"E";
					if(ans[i]=='#')
					ans[i]='E';
				}
				else{
					// cout<<"W";
					if(ans[i]=='#')
					ans[i]='W';
				}
			}

		}
		for(int i=0;i<ans.size();i++){
			if(ans[i]=='#'){
				break;
			}
			else{
				cout<<ans[i];
			}
		}
		// for(int i=0;i<60;i++){
		// 	if((x&(1LL<<i))!=0 && ((y&(1LL<<i)))!=0){
		// 		f=0;

		// 	}
		// 	else{
		// 		if((x&(1LL<<i))==0 && ((y&(1LL<<i)))==0){

		// 		}
		// 		else if ((x&(1LL<<i))==0 && ((y&(1LL<<i)))!=0){
		// 			if(my==1){
		// 				cout<<"N";
		// 			}
		// 			else{
		// 				cout<<"S";
		// 			}
		// 		}
		// 		else if((x&(1LL<<i))!=0 && ((y&(1LL<<i)))==0){
		// 			if(mx==1){
		// 				cout<<"E";
		// 			}
		// 			else{
		// 				cout<<"W";
		// 			}
		// 		}
		// 	}
		// 	if(f==0){
		// 		break;
		// 	}
		// }
		// if(f==0){
		// 	cout<<"IMPOSSIBLE\n";
		// }

		cout<<"\n";

	}

	return 0;
}