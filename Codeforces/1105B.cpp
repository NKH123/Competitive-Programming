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
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	int a[26];
	memset(a,0,sizeof(a));
	int sam=0;
	bool flag=0;
	if(k==1){
		for(int i=0;i<n;i++){
			a[s[i]-'a']++;
		}
	}
	else{
		//cout<<"imhere\n";
		for(int i=1;i<(n);i++){
    	//trace(i);
			//trace(s[i]);
    	//trace(sam);
			if(s[i]==s[i-1]){
				//cout<<"here\n";
				sam++;
				if((sam%(k-1))==0 && flag!=1){
					a[s[i]-'a']++;
					sam=0;
					flag=1;
				}
				else if((sam%(k-1))==0){
					flag=0;
				}

			}
			else{
				sam=0;
				flag=0;
			}
			//trace(sam);
		}
	}
	int ans=0;
	for(int i=0;i<26;i++){
		ans=max(ans,a[i]);
	}
	cout<<ans<<"\n";
	return 0;
}