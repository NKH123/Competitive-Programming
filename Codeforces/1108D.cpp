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
int ans=0;
string s;
void fun(int I){
	//trace(I);
	int n=s.size();
	int len=1;
	for(int i=I;i<(n-1);i++){
		if(s[i]==s[i+1]){
			len++;
		}
		else{
			break;
		}

	}
	//trace(len);
	char rep;
	if(s[I]=='R'){
		rep='G';
	}
	if(s[I]=='G'){
		rep='B';
	}
	if(s[I]=='B'){
		rep='R';
	}
	if(len%2==0){
		/*if(I==0){

		}
		else{

		}*/
		if(I!=0){
			if (rep==s[I-1]){
				rep='R'+'G'+'B'-rep-s[I];
			}
		}
		for(int i=0;i<len;i++){
			if(i%2==0){
				s[i+I]=rep;
				ans++;
			}
		}
	}
	else{
		for(int i=0;i<len;i++){
			if((i%2)!=0){
				s[i+I]=rep;
				ans++;
			}
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

	cin>>s;
	for(int i=0;i<(n-1);i++){
		if(s[i]==s[i+1]){
			fun(i);
		}
	}
	cout<<ans<<"\n";
	cout<<s<<"\n";		
	return 0;
}