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
    vector<pair<char,char> >a;
    map<char,char>m;
    map<char,char>pp;
    m.clear();
    while(t--){
    	m.clear();
    	pp.clear();
    	int n,mm;
    	string s;
    	cin>>n>>mm;
    	cin>>s;
    	while(mm--){
    		char A,B;
    		cin>>A>>B;
    		a.PB({A,B});;
    		if(A>B){
    			m[A]=B;
    		}
    		else{
    			pp[A]=B;

    		}
    	}
    	for(auto g:pp){
    		if(m.count(g.S)){
    			m[g.F]=m[g.S];
    		}
    	}
    	for(auto g:m){
    		if(m.count(g.S)){
    			m[g.F]=m[g.S];
    		}
    	}
    	for(auto g:m){
    		if(m.count(g.S)){
    			m[g.F]=m[g.S];
    		}
    	}
    	for(int i=0;i<s.size();i++){
    		if(m.count(s[i])){
    			s[i]=m[s[i]];
    		}
    	}
    	cout<<s<<"\n";
    }
    return 0;
}