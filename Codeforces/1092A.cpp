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
    vector<char>s;
    while(t--){
    	int n,k;
    	cin>>n>>k;
    	s.clear();
    	char a='a';
    	int ti=n/k;
    	s.resize(n);
    	int i;
    	for( i=0;i<(ti*k);i++){
    		if(i!=0 && i%ti==0){
    			a++;
    		}
    		s[i]=a;

    	}
    	i--;
    	if(i!=n-1){
    		while(i<n){
    			s[i]=a;
    			i++;
    		}
    	}
    	for(auto d:s){
    		cout<<d;
    	}
    	cout<<"\n";

    }


    return 0;
}