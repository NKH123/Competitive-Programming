#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <b; i++)
#define print(x) cout<<#x<<" is "; for(int i=0;i<x.size();i++){cout<<x[i]<<" ";}cout<<"\n"
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
    	string s;
    	cin>>s;
    	vi a;
    	a.clear();
    	//int k=0
    	vector<char>b;
    	b.clear();
    	for(int i=0;i<s.size();i++){
    		//trace(i);
    		//trace(s[i]);
    		if(i==0){
    			a.PB(s[i]-'0');
    		}
    		else if(s[i]>='0' && s[i]<='9'){
    			a[a.size()-1]=a[a.size()-1]*10+s[i]-'0';
    		}
    		else{
    			//cout<<"I'm here\n";
    			b.PB(s[i]);
    			a.PB(0);
    		}
    	}
    	ll res=a[0];
    	//print(a);
    	//print(b);
    	int k=0;
    	for(int i=0;i<3;i++){
    		if(b[i]=='+'){
    			res=res+a[k+1];

    		}
    		if(b[i]=='-'){
    			res-=a[k+1];
    		}
    		if(b[i]=='*'){
    			res*=a[k+1];
    		}
    		k++;

    	}
    	if(res!=a[a.size()-1]){
    		cout<<"Invalid Equation\n";
    	}
    	else{
    		cout<<"Valid Equation\n";
    	}
    }
    
    return 0;
}