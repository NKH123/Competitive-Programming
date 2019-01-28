#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int b,c,k;
		int a[3];
		cin>>k>>a[0]>>a[1]>>a[2];
		int f=0;
		for(int i=0;i<8;i++){
			int sum=0;
			for(int j=0;j<3;j++){
				if(i&(1<<j)){
					sum+=a[j];
				}
				else{
					sum-=a[j];
				}
			}
			if(sum==k){
				f=1;
			}

		}
		
		if(f==1)cout<<"WIN\n";
		else cout<<"LOSE\n";
	}
	return 0;
}