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
    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out","w",stdout);
    //freopen("b.in", "r", stdin);
    //freopen("c.in", "r", stdin);
    //freopen("d.in", "r", stdin);
    ll c1,c2,c3,m1,m2,m3;
    cin>>c1>>m1>>c2>>m2>>c3>>m3;
    for(int i=1;i<=100;i++){
    	int d=i%3;
    	if(d==1){
    		if(m2==c2){
    			continue;
    		}
    		else if(m1+m2<=c2){
    			m2=m1+m2;
    			m1=0;
    		}
    		else{
    			ll M=m2;
    			m2=m2+min(m1,c2-m2);
    			m1=m1-min(m1,c2-M);
    		}
    	}
    	if(d==2){
    			if(m3==c3){
    			continue;
    		}
    		else if(m2+m3<=c3){
    			m3=m2+m3;
    			m2=0;
    		}
    		else{
    			ll M=m3;
    			m3=m3+min(m2,c3-m3);
    			m2=m2-min(m2,c3-M);
    		}

    	}
    	if(d==0){
    			if(m1==c1){
    			continue;
    		}
    		else if(m3+m1<=c1){
    			m1=m3+m1;
    			m3=0;
    		}
    		else{
    			ll M=m1;
    			m1=m1+min(m3,c1-m1);
    			m3=m3-min(m3,c1-M);
    		}

    	}
    	/*trace(i);
    	cout<<m1<<"\n"<<m2<<"\n"<<m3<<"\n";*/
	}
	/*cout<<"Ans\n";*/
	cout<<m1<<"\n"<<m2<<"\n"<<m3<<"\n";


    return 0;
}