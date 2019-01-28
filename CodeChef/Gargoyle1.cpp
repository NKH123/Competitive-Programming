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
	vector<string>ss(n);
	vector<bool>aa(n);
	set<string>S;
	vector<string>vv(n,"");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			string s;
			cin>>s;
			vv[i]+=s;
		}
		ss[i]=vv[i];
	}
    /*REP(i,0,n){
    	cout<<ss[i]<<"\n";
    }*/
    REP(i,0,n){//cin>>ss[i];

    	if(ss[i][i]=='T'){
    		aa[i]=true;
    	}
    	else{
    		aa[i]=false;
    	}
    }
    /*REP(i,0,n){
    	cout<<aa[i]<<" ";
    }
    cout<<"\n";*/
    for(int i=0;i<n;i++){
    	int f=0;
    	if(aa[i]==true){
    		for(int j=0;j<n;j++){
    			/*if(ss[i][j]=='F'){
    				if(aa[j]==true){
    					//f=0;
    				}
    				else{
    					f=1;
    					//break;
    				}
    			}*/
    			if(ss[i][j]=='T'){
    				/*if(ss[j][i]!='T' || ss[j][j]!='T'){
    					f=1;
    					//break;
    				}
    				else{
    					//f=0;
    				}*/
    				if(ss[i]!=ss[j]){
    					f=1;
    				}
    			}
    		}
    		if(f==0){
    		//cout<<"I'm here\n";
    			S.insert(ss[i]);
    		}
    	}
    }
    ll ans=0;
    ll ans1=0;
    for(auto g:S){
    	//cout<<g<<" ";
    	ans1=0;
    	for(int i=0;i<n;i++){
    		if(g==ss[i]){
    			ans1++;
    		}
    	}
    	ans=max(ans,ans1);
    }
    cout<<ans<<"\n";
    return 0;
}