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
    int t;
    cin>>t;
    while(t--){
    	int f=0;	
    	ll l,r;
    	cin>>l>>r;
    	ll R,L;
    	R=r;
    	L=l;
    	if(r%2==0){
    		R--;
    	}
    	if(l%2==0){
    		L++;
    	}
    	if(l==r){
    		if(l%2){
    			f=1;
    		}
    	}
    	ll oddno=((R+1)/2)-((L+1)/2)+1;
    	if(oddno%2==1){
    		f=1;
    	}
    	if(f==1){
    		cout<<"Odd\n";
    	}
    	else{
    		cout<<"Even\n";
    	}
    }
    
    return 0;
}