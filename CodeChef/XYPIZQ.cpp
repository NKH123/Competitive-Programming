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

int main()
{   ios::sync_with_stdio(false);
    //freopen("a.in", "r", stdin);
    //freopen("b.in", "r", stdin);
    //freopen("c.in", "r", stdin);
    //freopen("d.in", "r", stdin);
	int T;
	cin>>T;
	ll n,t,x,y,z;
	while(T--){
		cin>>n>>t>>x>>y>>z;
		ll num=1;
		ll den=2*n+1;
		if(t==1){
			if(x>y){
				if(y>z){
					num=num*den-(y-1);
					while(__gcd(num,den)!=1){
						ll x=__gcd(num,den);
						num=num/x;
						den=den/x;
					}
				}
				else{
					num=(y+1)*num;
				}
			}
			else{
				if(y==n && z==n){
					num=n*num;
				}
				else if(y>z){
					num=(y-1)*num;
				}
				else{
					num=num*den-(y+1);
					while(__gcd(num,den)!=1){
						ll x=__gcd(num,den);
						num=num/x;
						den=den/x;
					}
				}
			}
		}
		if(t==2){
			if(y==n){

			}
			else{
				num=num*den-(2*y);
				while(__gcd(num,den)!=1){
					ll x=__gcd(num,den);
					num=num/x;
					den=den/x;
				}
			}
		}
		if(t==3){
			if(x==0){
				den=1;
			}
			else if(x<y){
				if(z>y){
					num=num*den-(y-1);
					while(__gcd(num,den)!=1){
						ll x=__gcd(num,den);
						num=num/x;
						den=den/x;
					}
				}
				else{
					num=(y-1)*num;
				}
			}
			else{
				if(z>y){
					num=(y+1)*num;
				}
				else{
					num=num*den-(y+1);
					while(__gcd(num,den)!=1){
						ll x=__gcd(num,den);
						num=num/x;
						den=den/x;
					}

				}
			}
		}
		if(t==4){
			if(y==0 || y==n){
				if(y==0){
					den=1;
				}
				else{

				}
			}
			else{
				num=num*den-(2*y);
				while(__gcd(num,den)!=1){
					ll x=__gcd(num,den);
					num=num/x;
					den=den/x;
				}
			}
		}
		while(__gcd(num,den)!=1){
			ll x=__gcd(num,den);
			num=num/x;
			den=den/x;
		}
		cout<<num<<" "<<den<<"\n";

	}

	return 0;
}