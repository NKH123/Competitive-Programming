#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;

int main(){
	ll n;
	cin>>n;
	ll a=n;
	ll b=n+1;
	ll c=a*b;
	if((a*b)%4==0){
		cout<<0<<"\n";
	}
	else{
		cout<<1<<"\n";
	}

	return 0;
}