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
    vi a(n);
    REP(i,0,n)cin>>a[i];
    sort(a.begin(),a.end());
    int k,cost=0;
    int Cost=1<<18;
    /*for(int i=-1;i<2;i++){
    	//if(((n/2)+i)>=0 && ((n/2)+i)<=(n-1)){
    	int x=a[(n/2)];
    	x=x+i;
    	cost=0;
    	for(int i=0;i<n;i++){
    		if(a[i]<x){
    			cost+=(x-1)-a[i];
    		}
    		else if(a[i]>x){
    			cost+=a[i]-(x+1);
    		}
    	}
    	if(Cost>cost){
    		Cost=cost;
    		k=x;
    	}
    //}
    }*/
    for(int x=1;x<150;x++){
    	//trace(x);
    	cost=0;
    	for(int i=0;i<n;i++){
    		if(a[i]<x){
    			cost+=(x-1)-a[i];
    		}
    		else if(a[i]>x){
    			cost+=a[i]-(x+1);
    		}
    	}
    	//trace(cos)
    	if(Cost>cost){
    		Cost=cost;
    		k=x;
    	}
    }
    cout<<k<<" "<<Cost<<"\n";
    
    return 0;
}