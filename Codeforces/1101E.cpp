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
    ll lmax=-1,wmax=-1;
    while(n--){
    	char a;
    	ll l,w;
    	cin>>a;
    	cin>>l>>w;
    	//cout<<a<<" "<<l<<" "<<w<<"\n";
    	if(l>w){
    		swap(l,w);
    	}
    	if(a=='+'){
    		lmax=max(lmax,l);
    		wmax=max(wmax,w);
    		//trace(lmax);
    		//trace(wmax);
    	}
    	else{
    		//cout<<"In else\n";
    		//trace(l);
    		//trace(lmax);
    		//trace(w);
    		//trace(wmax);
    		if(l< lmax || w<wmax){
    			cout<<"NO\n";
    		}
    		else{
    			cout<<"YES\n";
    		}
    	}



    }

    
    return 0;
}