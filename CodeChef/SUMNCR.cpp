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
bool check1 (ll x){
	x++;
	unsigned int count = 0; 
	while (x) 
	{ 
		count += x & 1; 
		x >>= 1; 
	} 
	if(count==1)
		return true;
	else{
		return false;
	} 
} 

ll getPosOfRightmostSetBit(ll n) 
{ 
	return log2(n&-n)+1; 
} 

// function to get the position of rightmost unset bit 
ll getPosOfRightMostUnsetBit(ll n) 
{ 
    // if n = 0, return 1 
	if (n == 0) 
		return 1; 

    // if all bits of 'n' are set 
	if ((n & (n + 1)) == 0)     
		return -1; 

    // position of rightmost unset bit in 'n' 
    // passing ~n as argument 
	return getPosOfRightmostSetBit(~n);         
} 
int main()
{   ios::sync_with_stdio(false);
    //freopen("a.in", "r", stdin);
    //freopen("b.in", "r", stdin);
    //freopen("c.in", "r", stdin);
    //freopen("d.in", "r", stdin);
	int t;
	cin>>t;
	int k;
	vector<long long> a;
	while(t--){
		ll ans=0;
		cin>>k;
		a.resize(k);
		REP(i,0,k){cin>>a[i];

		}
		int odd=0,even=0;
		for(int i=0;i<k;i++){
			if(a[i]%2==0){
				even++;
			}
			else{
				odd++;
			}
		}
		if(k==1){
			if(a[0]%2==0){
				ans+=1;
			}
			else{
				if(check1(a[0])){
					ans=-1;
				}
				else{
					int x=getPosOfRightMostUnsetBit(a[0])-1;
					ans=1L<<x;

				}
			}
		}
		else{
			
			if(k%2==0){
				ans=0;
			}
			else{
				if(odd==0){
					ans=1;
				}
				else if(even==0){
					ll ans1=1L<<31;
					ans=1L<<31;
					for(int i=0;i<k;i++){
						if(check1(a[i])){
							ans1=1L<<31;
							ans=min(ans,ans1);
						}
						else{
							int x=getPosOfRightMostUnsetBit(a[i])-1;
							ans1=1L<<x;
							ans=min(ans,ans1);
						}
					}
					if(ans==(1L<<31)){
						ans=-1;
					}
				}
				else{
					if(even%2==0){
						ans=1;
					}
					else{
						ans=1;
					}
				}
			}
		}
		cout<<ans<<"\n";
	}



return 0;
}