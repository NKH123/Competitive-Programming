#include<bits/stdc++.h>
#define ll long long
using namespace std;


bool a[1000005];
int MAX=1000005;
vector<ll> primes;
ll SPF[1000005];
void prec(){
	//seive;
	a[0]=a[1]=false;
	for(ll i=2;i<(MAX);i++){
		if(a[i]){
			primes.push_back(i);
			SPF[i]=i;


		}
		for(ll j=0;j<(ll)primes.size() && i*primes[j]<(MAX) && primes[j]<=SPF[i];j++){
			a[i*primes[j]]=false;
			SPF[i*primes[j]]=primes[j];
		}
	}

}
vector<long long>ans;

int main(){
	memset(a,true,sizeof(a));
	prec();
	/*for(auto g:primes){
		cout<<g<<" ";
	}*/
	/*cout<<"The number of primes is "<<primes.size()<<"\n";
	for(int i=0;i<100;i++){
		cout<<primes[i]<<" ";
	}
	cout<<"\n";*/
	int t;
	int n;
	cin>>t;
	while(t--){
		cin>>n;
		ans.resize(n);
		for(int i=0;i<n;i++){
			ans[i]=1;
		}
		int k=0;
		for(int i=0;i<n;i++){
			if(i==(n-1)){
				ans[n-1]=ans[n-1]*primes[n-1];
				ans[0]=ans[0]*primes[n-1];
			}
			else{
				ans[i]=ans[i]*primes[i];
				ans[i+1]=ans[i+1]*primes[i];
			}
		}
		for(int i=0;i<n;i++){
			cout<<ans[i]<<" ";
		}
		cout<<"\n";





	}
	return 0;
}