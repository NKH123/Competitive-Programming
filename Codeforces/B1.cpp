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
    //freopen("a.in", "r", stdiitn);
    //freopen("b.in", "r", stdin);
    //freopen("c.in", "r", stdin);
    //freopen("d.in", "r", stdin);
    string s;
    cin>>s;
    int lbr=-1,rbr=-1,lco=-1,rco=-1;
    for(int i=0;i<s.size();i++){
    	if(s[i]=='['){
    		lbr=i;
    		break;
    	}
    }
    if(lbr==-1){
    	cout<<-1<<"\n";
    	return 0;
    }
    for(int i=lbr;i<s.size();i++){
    	if(s[i]==']'){
    		rbr=i;
    		
    	}
    }
    if(rbr==-1){
    	cout<<-1<<"\n";
    	return 0;
    }
    for(int i=lbr;i<rbr;i++){
    	if(s[i]==':'){
    		lco=i;
    		break;
    	}
    }
    if(lco==-1){
    	cout<<-1<<"\n";
    	return 0;
    }
    for(int i=lco+1;i<rbr;i++){
    	if(s[i]==':'){
    		rco=i;

    	}
    }
    if(rco==-1){
    	cout<<-1<<"\n";
    	return 0;
    }
    int ans=4;
    for(int i=lco;i<rco;i++){
    	if(s[i]=='|'){
    		ans++;
    	}
    }
    cout<<ans<<"\n";


    
    return 0;
}