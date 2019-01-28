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
    string s;
    cin>>s;
    int i,j;
    ll left=1;
    for(int i=1;i<s.size();i++){
    	if(s[i]!=s[i-1]){
    		break;
    	}
    	else{
    		left++;
    	}
    }
    ll right=1;
    for(int i=s.size()-1;i>0;i--){
    	if(s[i]!=s[i-1]){
    		break;
    	}
    	else{
    		right++;
    	}
    }
    //trace(left);
    //trace(right);

    if(s[left-1]==s[n-right]){
    	//cout<<"1here\n";
    	cout<<((left+1)*(right+1))%998244353L<<"\n";
    }
    else{
    	//cout<<"2here\n";
    	cout<<((left+1)+right)%998244353<<"\n";
    }
    
    return 0;
}