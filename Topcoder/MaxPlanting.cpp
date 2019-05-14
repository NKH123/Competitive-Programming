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
class MaxPlanting{
public:
	int most(int width, int height, int size, int max){
		// int ans=0;
		// for(int i=size;i<=height;i++){
		// 	for(int j=size;j<=width;j++){
		// 		deb(i);
		// 		deb(j);
		// 		ans+=max;
		// 	}
		// }
		// return ans;
		int a[width+1][height+1];
		memset(a,0,sizeof(a));
		for(int i=0;i<=(height-size);i++){
			for(int j=0;j<=(width-size);j++){
				int count=0;
				int I=i;
				int J=j;
				for(I=i;I<(i+size);I++){
					for(J=j;J<(j+size);J++){
						if(a[I][J])count++;
					}
				}
				if(count<max){

					int I=i;
					int J=j;
					int ct=count;
					if(i==0 && j==0){
						for(int I=0;I<(size);I++){
							for(int J=0;J<size;J++){
								if(ct==max){
									I=i+size+1;
									J=j+size+1;
								}
								else if(!a[I][J]){
									a[I][J]=1;
									ct++;
								}
								
							}
						}
					}
					else if(i==0){
						J=j+size-1;
						for(;I<(i+size);I++){
							if(ct==max){
								I=i+size+1;
							}
							else if(!a[I][J]){
								a[I][J]=1;
								ct++;
							}
							
						}
					}
					else if(j==0){
						I=i+size-1;
						for(;J<(j+size);J++){
							if(ct==max){
								J=j+size+1;
							}
							else if(!a[I][J]){
								a[I][J]=1;
								ct++;
							}
							
						}
						
					}
					else{
						a[i+size-1][j+size-1]=1;
						ct++;
					}
					
				}
			}
		}
		int ans=0;
		for(int i=0;i<height;i++){
			for(int j=0;j<width;j++){
				cout<<a[i][j];
				if(a[i][j])ans++;
			}
			cout<<"\n";
		}
		return ans;
	}
};



int32_t main(){
	MaxPlanting M;

	cout<<M.most(3,3,2,1)<<"\n";

	return 0;
}

