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
#define print(x) cout<<#x<<" is "; for(int i=0;i<x.size();i++){cout<<x[i]<<" ";}cout<<"\n"
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
 vi a;
ll fun(int A,int B,int C){
	ll ret=0;
	for(int i=0;i<a.size();i++){
		if((i%3)==0){
			if(a[i]!=A){
				ret++;
			}
		}
		if((i%3)==1){
			if(a[i]!=B){
				ret++;	
			}
		}
		if((i%3)==2){
			if(a[i]!=C){
				ret++;
			}
		}
	}
	return ret;
}
void p(int A){
	if(A==1){
		cout<<"B";
	}
	if(A==2){
		cout<<"G";
	}
	if(A==3){
		cout<<"R";
	}
}
void f1(int f){
	int A,B,C;
	switch(f){
		case 0: A=1;B=2;C=3; break;
		case 1: A=1;B=3;C=2; break;
		case 2: A=2;B=1;C=3; break;
		case 3: A=2;B=3;C=1; break;
		case 4: A=3;B=1;C=2; break;
		case 5: A=3;B=2;C=1; break;
	}
	for(int i=0;i<a.size();i++){
		if((i%3)==0){
			p(A);
		}
		if((i%3)==1){
			p(B);
		}
		if((i%3)==2){
			p(C);
		}
	}
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
   
    a.resize(n);
    REP(i,0,n){
    	if(s[i]=='B')a[i]=1;
    	if(s[i]=='G')a[i]=2;
    	if(s[i]=='R')a[i]=3;
    }
    ll ans=1L<<30;
    int f=-1;
    ll Ans;
    Ans=min(ans,fun(1,2,3));
    if(Ans!=ans){
    	f=0;
    	ans=Ans;
    }
    Ans=min(ans,fun(1,3,2));
    if(Ans!=ans){
    	f=1;
    	ans=Ans;
    }
    Ans=min(ans,fun(2,1,3));
    if(Ans!=ans){
    	f=2;
    	ans=Ans;
    }
    Ans=min(ans,fun(2,3,1));
    if(Ans!=ans){
    	f=3;
    	ans=Ans;
    }
    Ans=min(ans,fun(3,1,2));
    if(Ans!=ans){
    	f=4;
    	ans=Ans;
    }
    Ans=min(ans,fun(3,2,1));
    if(Ans!=ans){
    	f=5;
    	ans=Ans;
    }

    cout<<ans<<"\n";
    f1(f);
    cout<<"\n";


    return 0;
}