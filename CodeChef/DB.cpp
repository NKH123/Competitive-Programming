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
#define llp 1000000007
#define mod 1000000007


ll power(ll x, ll y) 
{
	ll temp;
	if( y == 0)
		return 1;
	temp = power(x, y/2);
	if (y%2 == 0)
		return (temp*temp)%mod;
	else
		return (((x*temp)%mod)*temp)%mod; 
}
vector<vector<int> >a;
vector<vector<int> >b;
int n,m;
set<int >s;
set<int >ss;
int mini;
int maxi;
vi rem;
void valinsert(int i,int j){
	if(i>=0 && (j>=0 && j<=(m-1))){
		ss.insert(a[i][j]);
	}
}
int getno(int i,int j){
	ss.clear();
	rem.clear();
	valinsert(i-2,j);
	valinsert(i-1,j+1);
	valinsert(i-1,j-1);
	valinsert(i,j-2);
	/*if(ss.size()==0){
		return 1;
	}
	else{
		int ret=1;
		while(ss.find(ret)!=ss.end()){
			ret++;
			
		}
		return ret;
	}*/
	for(int i=1;i<=4;i++){
		if(ss.find(i)==ss.end()){
			rem.PB(i);
		}
	}

}
bool nei(int i, int j){
	int ma=4;
	s.clear();
	if((i-1)>=0){
		s.insert(a[i-1][j]);
	}
	else{
		ma--;
	}
	if((j-1)>=0){
		s.insert(a[i][j-1]);
	}
	else{
		ma--;
	}
	if((j+1)<=(m-1)){
		s.insert(a[i][j+1]);
	}
	else{
		ma--;
	}
	if((i+1)<=(n-1)){
		s.insert(a[i+1][j]);
	}
	else{
		ma--;
	}
	if(s.size()!=ma){
		return false;
	}
	else{
		return true;
	}
}
bool correct(){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			mini=max(mini,a[i][j]);
			if(!nei(i,j)){
				return false;
			}

		}
	}
	return true;
}
bool check1(int i,int j,int k){
	if(i>=0 && (j>=0 && j<=(m-1))){
		if(a[i][j]==k){
			return true;
		}
	}
	return false;

}
bool check(int i, int j,int k){
	/*
		valinsert(i-2,j);
	valinsert(i-1,j+1);
	valinsert(i-1,j-1);
	valinsert(i,j-2);*/
	if(check1(i-2,j,k)){
		return false;
	}
	else if(check1(i-1,j+1,k)){
return false;
	}
	else if(check1(i-1,j-1,k)){
return false;
	}
	else if(check1(i,j-2,k)){
return false;
	}
	return true;


}
void solve(int i,int j){
	//trace(i);
	//trace(j);
	int I=i;
	int J=j;
	int f=0;
	if(J==(m-1)){
		J=-1;
		/*if(I==(n-1)){
			f=1;
		}
		else{
			I++;
		}*/
		I++;
	}
	/*if(J==m){
		J=0;
		I++;
	}*/
	if(i==n && j==0){
	//	cout<<"yoyo\n";
	/*	for(int i=0;i<n;i++){
				for(int j=0;j<m;j++){
					cout<<a[i][j]<<" ";
				}
				cout<<"\n";
			}
	*/	mini=-1;
		if(correct()){
	//		cout<<"correct************"<<mini<<"\n";
	//		trace(maxi);
			if(maxi==-1 || maxi>mini){
				for(int i=0;i<n;i++){
					for(int j=0;j<m;j++){
	//					cout<<a[i][j]<<" ";
						b[i][j]=a[i][j];
					}
	//				cout<<"\n";
				}
				maxi=mini;
			}
			/*for(int i=0;i<n;i++){
				for(int j=0;j<m;j++){
					cout<<a[i][j]<<" ";
				}
				cout<<"\n";
			}*/		}
			return;
			//done
		}
		if(check(i,j,1)){
			//cout<<"selected1\n";
		a[i][j]=1;
		solve(I,J+1);
	}
	if(check(i,j,2)){
		//cout<<"selected2\n";
		a[i][j]=2;
		solve(I,J+1);
	}
	if(check(i,j,3)){
		//cout<<"selected3\n";
		a[i][j]=3;
		solve(I,J+1);
	}
	if(check(i,j,4)){
		//cout<<"selected4\n";
		a[i][j]=4;
		solve(I,J+1);
	}
	/*a[i][j]=1;
		solve(I,J+1);
		a[i][j]=2;
		solve(I,J+1);
		a[i][j]=3;
		solve(I,J+1);
		a[i][j]=4;
		solve(I,J+1);*/
		/*getno(i,j);
		if(i==0 && j==0){
			a[i][j]=1;
			solve(I,J+1);	
		}
		else{
			if(i==0 && j==4){
				cout<<"Yo***********************************************************************************************\n";
				for(auto g:rem){
					cout<<g<<" ";
				}
				cout<<"\n";
			}
		for(auto g:rem){

			a[i][j]=g;
			solve(I,J+1);
		}
	}*/


	}
	int main()
	{   ios::sync_with_stdio(false);
    //freopen("a.in", "r", stdin);
    //freopen("b.in", "r", stdin);
    //freopen("c.in", "r", stdin);
    //freopen("d.in", "r", stdin);
		int t;
		cin>>t;
		while(t--){
			maxi=654654;
			cin>>n>>m;
			a.resize(n);
			REP(i,0,n){
				a[i].resize(m);
			}
			b.resize(n);
			REP(i,0,n){
				b[i].resize(m);
			}
			solve(0,0);
			cout<<"I'm here         mini=";
			cout<<maxi<<"\n";
			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++){
					cout<<b[i][j]<<" ";
				}
				cout<<"\n";
			}

		}
		return 0;
	}