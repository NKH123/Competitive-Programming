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
vector<long long>ans;

int main(){
	memset(a,true,sizeof(a));
	prec();
	/*cout<<"The size is= "<<primes.size()<<"\n";
	cout<<primes[primes.size()-1]<<"\n";*/
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
			ans[i]=primes[i+3];
		}
		int k=0;
		if(n==5){
			cout<<22<<" "<<6<<" "<<15<<" "<<35<<" "<<77<<"\n";
		}
		else{
		for(int i=0;i<n;i++){
			if(i==(n-1)){

				ans[n-1]=ans[n-1]*primes[6];
				ans[0]=ans[0]*primes[6];
			}
			else{
				int k=i%4;
				if(k==0){
					ans[i]=ans[i]*primes[0];
					ans[i+1]=ans[i+1]*primes[0];
				}
				if(k==1){
					ans[i]=ans[i]*primes[1];
					ans[i+1]=ans[i+1]*primes[1];

				}
				if(k==2){
					ans[i]=ans[i]*primes[2];
					ans[i+1]=ans[i+1]*primes[2];

				}
				if(k==3){
					ans[i]=ans[i]*primes[3];
					ans[i+1]=ans[i+1]*primes[3];
				}
				/*ans[i]=ans[i]*primes[i];
				ans[i+1]=ans[i+1]*primes[i];*/
			}
		}
		if( (n%4)==1){
			ans[n-2]=ans[n-2]/primes[3];
			ans[n-1]=ans[n-1]/primes[3];
			//ans[n-1]=ans[n-1]/primes[6];
			//ans[0]=ans[0]/primes[6];
			ans[n-2]=ans[n-2]*primes[5];
			ans[n-1]=ans[n-1]*primes[5];
			//ans[n-1]=ans[n-1]*primes[7];
			//ans[0]=ans[0]*primes[7];

		}
		if((n%4)==2){
			ans[n-2]=ans[n-2]/primes[0];
			ans[n-1]=ans[n-1]/primes[0];
			ans[n-2]=ans[n-2]*primes[5];
			ans[n-1]=ans[n-1]*primes[5];


		}
		for(int i=0;i<n;i++){
			cout<<ans[i]<<" ";
		}
		cout<<"\n";
		int f=0;
		/*for(int i=0;i<n;i++){
			if(__gcd(ans[i],ans[(i+1)%n])==1){
				f=1;
				cout<<"i="<<i+1<<"\n";

				f=1;
				cout<<ans[i]<<" "<<ans[(i+1)%n]<<"\n";
				print(ans[i]);
				print(ans[(i+1)%n]);
				//print(ans[(i+2)%n]);
				cout<<"1NO\n";
				break;
			}
			if(__gcd(__gcd(ans[i],ans[(i+1)%n]),ans[(i+2)%n])!=1){
				cout<<"i="<<i+1<<"\n";

				f=1;
				cout<<ans[i]<<" "<<ans[(i+1)%n]<<" "<<ans[(i+2)%n]<<"\n";
				print(ans[i]);
				print(ans[(i+1)%n]);
				print(ans[(i+2)%n]);
				cout<<"2NO\n";
				break;
			}
			if(ans[i]>(1000000000)){
				f=1;
				cout<<"3NO\n";
				break;
			}
		}
		if(!f)
			cout<<"YES\n";*/
	}





	}
	return 0;
}