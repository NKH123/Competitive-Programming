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
ll a[26];
bool test(){
	for(int i=0;i<26;i++){
		if(a[i]!=0){
			return false;
		}

	}
	return true;
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
    
    REP(i,0,26){
    	a[i]=0;
    }
    for(int i=0;i<s.size();i++){
    	a[s[i]-'a']++;
    }
    ll ans=0;
    while(!test()){
    	ll mini=1LL<<60;
    	for(int i=0;i<26;i++){
    		if(a[i]!=0){
    			mini=min(mini,a[i]);

    		}
    	}
    	for(int i=0;i<26;i++){
    		if(a[i]!=0){
    			a[i]-=mini;
    		}
    	}
    	ans++;

    }
    cout<<ans<<"\n";
    
    return 0;
}