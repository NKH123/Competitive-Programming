#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int>a(n);
	int A,B,C,D,POS;	
	for(int i=0;i<n;i++)cin>>a[i];
		vector<bool>b(65,0);
	int f=0;
	for(int i=0;i<n-1;i++){
		int bit=a[i]^a[i+1];
		int pos=0;
		while(bit>0){
			if(bit%2){
				break;
			}
			pos++;
			bit=bit/2;
		}
		if(b[bit]==true){
			f=1;
			C=i+1;

			D=i+2;
			POS=pos;
			break;
		}

	}
	for(int i=0;i<n-1;i++){
		int bit=a[i]^a[i+1];
		int pos=0;
		while(bit>0){
			if(bit%2){
				break;
			}
			pos++;
			bit=bit/2;
		}
		if(POS==pos){
			A=i+1;
			B=i+2;
		}

	}
	if(f==0 || f==1 && B==C){
		cout<<"No\n";
	}
	else{
		cout<<"Yes\n";
		cout<<A<<" "<<B<<" "<<C<<" "<<D<<"\n";
	}
	return 0;
}