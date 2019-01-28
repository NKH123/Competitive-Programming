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
{   ios::sync_with_stdio(false);
    //freopen("a.in", "r", stdin);
    //freopen("b.in", "r", stdin);
    //freopen("c.in", "r", stdin);
    //freopen("d.in", "r", stdin);
	int n;
	cin>>n;
	string s;
	cin>>s;
	vi a(n);
	int A[3];
	A[0]=0;
	A[1]=0;
	A[2]=0;

	REP(i,0,n){
		a[i]=s[i]-'0';
		A[a[i]]++;
	}
	if(A[0]==(n/3) && A[1]==(n/3)){
		cout<<s<<"\n";
	}
	else{
		//int rem
		if(A[0]<(n/3)){
			int rem=(n/3)-A[0];
			if(A[1]>(n/3)){
				for(int i=0;i<n;i++){
					if(a[i]==1){
						a[i]=0;
						A[0]++;
						A[1]--;
						rem--;
					}
					if(A[1]==(n/3) || rem==0){
						break;
					}
				}
			}
			if(rem!=0)
				if(A[2]>(n/3)){
					for(int i=0;i<n;i++){
						if(a[i]==2){
							a[i]=0;
							A[0]++;
							A[2]--;
							rem--;
						}
						if(A[2]==(n/3) || rem==0){
							break;
						}
					}
				}
			}
			if(A[2]<n/3){
					int rem=(n/3)-A[2];
					if(A[0]>(n/3)){
						for(int i=n-1;i>=0;i--){
							if(a[i]==0){
								a[i]=2;
								A[0]--;
								A[2]++;
								rem--;
							}
							if(A[0]==(n/3) || rem==0){
								break;
							}
						}
					}
					if(rem!=0)
						if(A[1]>(n/3)){
							for(int i=n-1;i>=0;i--){
								if(a[i]==1){
									a[i]=2;
									A[2]++;
									A[1]--;
									rem--;
								}
								if(A[2]==(n/3) || rem==0){
									break;
								}
							}

						}


					}
			if(A[1]<n/3){
				int rem=(n/3)-A[1];
				if(A[0]>(n/3)){
					for(int i=n-1;i>=0;i--){
						if(a[i]==0){
							a[i]=1;
							A[0]--;
							A[1]++;
							rem--;
						}
						if(A[0]==(n/3) || rem==0){
							break;
						}
					}
				}
				if(rem!=0)
					if(A[2]>(n/3)){
						for(int i=0;i<n;i++){
							if(a[i]==2){
								a[i]=1;
								A[1]++;
								A[2]--;
								rem--;
							}
							if(A[2]==(n/3) || rem==0){
								break;
							}
						}
					}

				}
				
					for(auto g:a){
						cout<<g;
					}
					cout<<"\n";
				}



				return 0;
			}