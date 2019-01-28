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
    int y,r,b;
    cin>>y>>b>>r;
    /*if((y+1)<=b && (y+2)<=r){
    	//cout<<"Im here1\n";
    	cout<<3*(y+1)<<"\n";
    }
    else{
    	if(y==b and y==r){
    		//cout<<"Im here2\n";
    		cout<<3*(y-1)<<"\n";
    	}
    	if((y+1)>b and (y+2)<=r){
    		//cout<<"Im here3\n";
    		cout<<3*(b)<<"\n";
    	}
    	else
    		if((y+1)<=b and (y+2)>r){
    		//	cout<<"Im here4\n";
    			cout<<3*(r-1)<<"\n";
    		}
    	else if((y+1)>b and (y+2)>r){
    		//cout<<"I'm here4\n";
    		if(b==r ){
    			cout<<3*(b-1)<<"\n";
    		}
    		else{
    			if(b>r){
    				cout<<3*(r-1)<<"\n";
    			}
    			else{
    			cout<<3*b<<"\n";	
    			}
    			
    		}
    		
    		
    	}
    	
    }
    r--;
    b--;
    b--;
    int ans=min(y,r);
     ans=min(ans,b);*/
    int B=b;
    if(b>(y+1)){
    	B=y+1;
    }
    if(B>(r-1)){
    	B=min(B,r-1);
    }
    cout<<3*B<<"\n";

    
    return 0;
}