#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <b; i++)
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef pair<int,int> pi;
#define trace(x) cout<<#x<<"="<<x<<"\n";
#define llp 1000000007
#define mod 1000000007
vl a;
vl b;
int nn;
int no(int i,int n){
	if(i>n){
		return i-n;
	}
	else return i;
}
void fill(int I, int n){
	b.clear();
	I++;
	if(n==4){
		b.resize(4);
		int r=4;
		for(int i=I;i<I+2;i++){
			cout<<1<<" "<<i<<" "<<i+1<<" "<<i+2<<"\n";
			cin>>b[i-I];
		}
		cout<<1<<" "<<I+n-2<<" "<<I+n-1<<" "<<I<<"\n";
			cin>>b[2];
			cout<<1<<" "<<I+n-1<<" "<<I<<" "<<I+1<<"\n";
			cin>>b[3];    

		I--;
		a[I]=b[0]^b[2]^b[3];
		a[I+1]=b[0]^b[1]^b[3];
		a[I+2]=b[0]^b[1]^b[2];
		a[I+3]=b[1]^b[2]^b[3];
	}
	if(n==5){
		
		b.resize(5);
		for(int i=I;i<I+3;i++){
			cout<<1<<" "<<i<<" "<<i+1<<" "<<i+2<<"\n";
			cin>>b[i-I];
		}
		cout<<1<<" "<<I+n-2<<" "<<I+n-1<<" "<<I<<"\n";
			cin>>b[3];
			cout<<1<<" "<<I+n-1<<" "<<I<<" "<<I+1<<"\n";
			cin>>b[4];
		I--;
		a[I]=b[1]^b[2]^b[4];
		a[I+1]=b[2]^b[3]^b[0];
		a[I+2]=b[1]^b[3]^b[4];
		a[I+3]=b[0]^b[4]^b[2];
		a[I+4]=b[0]^b[1]^b[3];
		
	}
	if(n==7){
		
		b.resize(7);
		for(int i=I;i<I+5;i++){
			cout<<1<<" "<<i<<" "<<i+1<<" "<<i+2<<"\n";
			cin>>b[i-I];
		}
			cout<<1<<" "<<I+n-2<<" "<<I+n-1<<" "<<I<<"\n";
			cin>>b[5];
			cout<<1<<" "<<I+n-1<<" "<<I<<" "<<I+1<<"\n";
			cin>>b[6];
		ll all=0;
		REP(i,0,7){
			all=all^b[i];
		}
		I--;
		a[I+4]=all^b[1]^b[5];
		a[I+1]=b[1]^b[2]^a[I+4];       //a,b, ,d,e,f,g,
		a[I]=b[4]^b[5]^a[I+4];
		a[I+3]=b[0]^b[1]^a[I];
		a[I+6]=a[I+3]^b[3]^b[4];
		a[I+5]=a[I+1]^b[5]^b[6];
		a[I+2]=a[I+5]^b[2]^b[3];


	}
}


ll power(ll x, ll y) 
{
	ll temp;
	if( y == 0)
		return 1;
	temp = power(x, y/2);
	if (y%2 == 0)
		return (temp*temp)%mod;
	else
		return (((x*temp)%mod)*temp)%mod; 
}

int main()
{  // ios::sync_with_stdio(false);
    //freopen("a.in", "r", stdin);
    //freopen("b.in", "r", stdin);
    //freopen("c.in", "r", stdin);
    //freopen("d.in", "r", stdin);
	cout.flush();
	int t;
	
	cin>>t;
	int ans;


	while(t--){
		
		cin>>nn;
		a.clear();
		a.resize(nn);

		if(nn%4==0){
			for(int i=0;i<nn;i+=4){
				fill(i,4);
			}
		}
		else if(nn%4==1){
			fill(0,5);
			//n-=5;
			for(int i=5;i<nn;i+=4){
				fill(i,4);
			}
		}
		else if(nn%4==2){
			fill(0,5);
			fill(5,5);
			//n-=10;
			for(int i=10;i<nn;i+=4){
				fill(i,4);
			}

		}
		else if(nn%4==3){
			fill(0,7);
			for(int i=7;i<nn;i+=4){
				fill(i,4);
			}

		}

		/*int aa[2];
		REP(i,0,2){
			cout<<1<<" "<<i+1<<" "<<i+2<<" "<<i+3<<"\n";
			cin>>aa[i];
		}
		int start=0;
		if(aa[0]<aa[1]){
			start=aa[0]+1;
		}
		else{
			start=aa[1];
		}*/
		cout<<2<<" ";
		REP(i,0,a.size()){
			cout<<a[i]<<" ";
		
		}
		
		int grade;
		cin>>grade;
		if(grade!=1){
			return grade+100;
		}
	}

    return 0;
}