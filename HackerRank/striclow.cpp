#include<bits/stdc++.h>
using namespace std;
int main(){
	vector<int>a;
	a.resize(100);
	for(int i=0;i<100;i++){
		a[i]=i+1;
	}
	int k;
	cin>>k;
	int lo=0,hi=a.size()-1;
	int mid;
	while(lo<=hi){
		mid=(lo+hi)/2;
		if(a[mid]>=k){
			hi=mid-1;
		}
		else{
			lo=mid+1;
		}
	}
	cout<<a[hi]<<"\n";
	return 0;
}