#include<bits/stdc++.h>
using namespace std;
int n;
void print(int x){
	while(x%2==0){
		cout<<2<<" ";
		x=x/2;
	}
	for(int i=3;i<=x;i+=2){
		while(x%i==0){
			cout<<i<<" ";
			x=x/i;
		}
	}
	cout<<"\n";
	/*if(x==1){
		cout<<"\nYES\n";
	}
	else{
		cout<<"\nNO\n";
	}*/
}
int main(){
	while(1){
		cin>>n;
		print(n);
	}
	return 0;
}