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
    vi a;
    ll ss=0;
    int n;
    int f=0;
    ll Sum(int i){
    //	trace(i);
    //	trace(ss);
    	if(i==n){
    		if(ss%360==0){
    //			trace(ss);
    			if(f==0)
    			cout<<"YES\n";
    			f=1;
    		}
    		/*else{
    			cout<<"NO\n";
    		}*/
    	}
    	else{
    	ss=ss+a[i];
    	Sum(i+1);
    	ss=ss-2*a[i];
    	Sum(i+1);
    	ss=ss+a[i];
    }
    }

int main()
{   ios::sync_with_stdio(false);
    //freopen("a.in", "r", stdin);
    //freopen("b.in", "r", stdin);
    //freopen("c.in", "r", stdin);
    //freopen("d.in", "r", stdin);

    
    //int n;
    cin>>n;
    a.resize(n);
    ll sum=0;
    set<pair<int,int> >s;
    REP(i,0,n){
    	cin>>a[i];
    }
    	Sum(0);
    	/*if(s.size()==0){
    		s.insert({a[i],i});
    		s.insert({-1*a[i],i});
    	}
    	else{
    		for(auto g:s){
    			if(g.S==i){
    				continue;
    			}
    			s.insert({(g.F+a[i])%360,i});
    			int b=g.F-a[i];

    			s.insert({(g.F-a[i])%360,i});
    		}
    	}
    }
    set<int>ss;

    for(auto g:s){
    	ss.insert(g.F);
    }
    if(ss.find(0)!=ss.end()||ss.find(360)!=ss.end()){
    	cout<<"YES\n";
    }
    else{
    	cout<<"NO\n";
    }*/
    	if(f!=1){
    		cout<<"NO\n";
    	}
    
    return 0;
}