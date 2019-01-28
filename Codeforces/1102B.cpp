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
    vi a(n);
    vi ans(n);
    vi cc(5001,1);
    REP(i,0,n)cin>>a[i];
    vector<pair<int, int> > b(5001);
    for(int i=0;i<n;i++){
    	b[a[i]].F++;
    	b[a[i]].S=i;
    	ans[i]=cc[a[i]];
    	cc[a[i]]++;
    }
    for(auto g:b){
    	if(g.F>k){
    		cout<<"NO\n";
    		return 0;
    	}
    }
    int f=0;
    int maxk=0;

    vi aa[k+1];
    for(int i=0;i<n;i++){
    	aa[ans[i]].PB(i);
    }
    for(int i=1;i<(k+1);i++){
    	if(aa[i].size()==0){
    		for(int j=1;j<(k+1);j++){
    			if(j==i || aa[j].size()<=1)continue;
    			int x=aa[j][aa[j].size()-1];
    			aa[j].pop_back();
    			aa[i].PB(x);
    			ans[x]=i;
    			break;
    		}
    	}
    }
    cout<<"YES\n";
    	REP(i,0,n){
    		cout<<ans[i]<<" ";
    	}
    	cout<<"\n";
    /*for(auto g:cc){
    	if(k<=(g-1)){
    		f=1;
    	}
    	maxk=max(maxk,g-1);

    }
    trace(maxk);
    if(f==1){
    	cout<<"YES\n";
    	REP(i,0,n){
    		cout<<ans[i]<<" ";
    	}
    	cout<<"\n";

    }
    else{
    	cout<<"I'm here\n";
    	for(int i=(maxk+1);i<=k;i++){
    		for(int j=1;j<maxk;j++){
    			int f=0;
    			for(int k=0;k<n;k++){
    				if(ans[i]==j ){
    					if(f==0)
    					f=1;
    					else if(f==1){
    						ans[i]=i;
    						//i++;
    						break;
    					}
    				}

    			}
    		}
    	}
    	cout<<"YES\n";
    	REP(i,0,n){
    		cout<<ans[i]<<" ";
    	}
    	cout<<"\n";
    }
    */
    return 0;
}