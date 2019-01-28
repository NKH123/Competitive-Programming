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
    	ll N,k;
    	cin>>N>>k;
    	if(k==1){
    		if(N%2){
    			cout<<"Alice\n";
    		}
    		else{
    			cout<<"Bob\n";
    		}
    	}
    	else{
    		ll tu=1;
    		int f=0;
    		while(1){
    			N-=power(k,tu);
    			//trace(N);
    			//trace(tu);
   	 			if(N<0){
   	 				f=0;
   	 			//	cout<<"I'm here\n";
    				break;

    			}
    			
    			N-=power(k,tu);
    			//trace(N);
    			//trace(tu);
    			if(N<0){
    				f=1;
   	 			//	cout<<"I'm here\n";
    				break;

    			}
    			//N-=power(k,tu);
    			tu++;

    		}
    		if(f!=0){
    			cout<<"Alice\n";

    		}
    		else{
    			cout<<"Bob\n";
    		}
    	}
    }
    
    return 0;
}