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
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	vector<int> a(26,0);
	//memset(a,0,sizeof(a));
	int sam=0;
	bool flag=0;
	int i=0;
	string t;
	vector<char>T;
	t=s[0];
	T.PB(s[0]);
	/*while(i<(n-1)){
	//trace(i);
	//trace(t);
		if(s[i]==s[i+1]){
			t=t+s[i+1];
			if(i==(n-2)){
				a[t[0]-'a']+=t.size()/k;
				t=s[i+1];
			}
		}
		else{
			a[t[0]-'a']+=t.size()/k;
			t=s[i+1];

		}

		//trace(t);
		i++;
	}*/
	while(i<(n-1)){
		if(T.size()==0){
			//t=s[i];
			T.PB(s[i]);
		}
		if(s[i]==s[i+1]){
			//t=t+s[i+1];
			T.PB(s[i+1]);
		}
		else{
			//a[t[0]-'a']+=t.size()/k;
			a[T[0]-'a']+=T.size()/k;

			//t="";
			T.clear();
		}
		i++;
	}
	if(T.size()!=0){
		//a[t[0]-'a']=t.size()/k;
		//t="";
			a[T[0]-'a']+=T.size()/k;

			//t="";
			T.clear();
	}
	int ans=0;
	for(int i=0;i<26;i++){
		ans=max(ans,a[i]);
	}
	cout<<ans<<"\n";
	return 0;
}