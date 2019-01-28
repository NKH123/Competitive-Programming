#include<bits/stdc++.h>
using namespace std;
vector<int> A[100005];
int main(){
	while(1){
		for(int i=0;i<100005;i++){
			A[i].clear();
		}
		int a;
		cin>>a;
		for(int i=1;i<=a;i++){
			A[(a)%i].push_back(i);
		}
		for(int i=0;i<100005;i++){
			if(A[i].size()!=0){
				cout<<i<<"******************\n";
				for(auto g:A[i]){
					cout<<g<<" ";
				}
				cout<<"\n\n\n";
			}
		}
	}
	return 0;
}