#include<bits/stdc++.h>
using namespace std;
int b[50][50];
vector<vector<int> >a;
int n,m;
int mini;
set<int> s;
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
int main(){
	int even=0;
	int odd=2;
	for(int i=0;i<50;i++){
		for(int j=0;j<50;j++){
			if(i%2==0){
				if(j%2==0){
					even++;
					if(even>2){
						even=1;
					}
				}
				b[i][j]=even;
			}
			else{
				if(j%2==0){
					odd++;
					if(odd>4){
						odd=3;
					}
				}
				b[i][j]=odd;
			}
		}
	}
	
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<b[i][j]<<" ";
		}
		cout<<"\n";
	}
	a.resize(n);
	for(int i=0;i<n;i++){
		a[i].resize(m);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			//cout<<a[i][j]<<" ";
			a[i][j]=b[i][j];
		}
	//	cout<<"\n";
	}
	if(correct()){
		cout<<"YES\n";
	}
	else{
		cout<<"NO\n";
	}

	return 0;
}