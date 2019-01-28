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
	
	/*cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<b[i][j]<<" ";
		}
		cout<<"\n";
	}*/
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
	/*if(correct()){
		cout<<"YES\n";
	}
	else{
		cout<<"NO\n";
	}*/

	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		
		if(n>=3 && m>=3){
			cout<<4<<"\n";
			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++){
					cout<<b[i][j]<<" ";
				}
				cout<<"\n";
			}

		}
		else{
			int f=0;
			if(n>m){
				f=1;
				swap(n,m);
			}
			a.resize(n);
			for(int i=0;i<n;i++){
				a[i].resize(m);
			}
			if(n==1){
				if(m==1){
					cout<<1<<"\n";
					//cout<<1<<"\n";
					a[0][0]=1;
				}
				else if(m==2){
					cout<<1<<"\n";
					//	cout<<"1 1\n";
					a[0][0]=1;
					a[0][1]=1;
				}
				else{
					cout<<"2\n";
					int as=0;
					for(int i=0;i<m;i++){
						if(i%2==0){
							as++;
							if(as>2){
								as=1;
							}
							
						}
						a[0][i]=as;
					}
				}
			}
			if(n==2){
				if(m==2){
					cout<<2<<"\n";
					a[0][0]=1;
					a[0][1]=1;
					a[1][0]=2;
					a[1][1]=2;
				}
				else{
					cout<<3<<"\n";
					for(int i=0;i<2;i++){
						for(int j=0;j<m;j++){
							if(j%3==0){
								a[i][j]=1;
							}
							if(j%3==1){
								a[i][j]=2;
							}
							if(j%3==2){
								a[i][j]=3;
							}
						}
					}
				}

			}
			if(f==1){
				for(int i=0;i<m;i++){
					for(int j=0;j<n;j++){
						cout<<a[j][i]<<" ";
					}
					cout<<"\n";
				}
			}
			else{
				for(int i=0;i<n;i++){
					for(int j=0;j<m;j++){
						cout<<a[i][j]<<" ";
					}
					cout<<"\n";
				}
			}
		}
	}

	return 0;
}