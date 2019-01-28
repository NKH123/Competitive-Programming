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
vector<int>adj[100005];

int main()
{   ios::sync_with_stdio(false);
    //freopen("a.in", "r", stdin);
    //freopen("b.in", "r", stdin);
    //freopen("c.in", "r", stdin);
    //freopen("d.in", "r", stdin);
    int n,k;
    cin>>n>>k;
    vl h(n);
    vl h1(n);
    vl h2(n);
    vector<pair<ll,ll> >HH(n);
    REP(i,0,n){
    	cin>>h[i];
    	h1[i]=h[i];
    	h2[i]=h1[i];
    	HH[i]={h[i],i+1};
    }
    sort(h1.begin(),h1.end());
    sort(h2.begin(),h2.end());
    sort(HH.begin(),HH.end());
    h2.resize(distance(h2.begin(),unique(h2.begin(),h2.end())));
   /* cout<<"h2= \n";
    REP(i,0,h2.size()){
    	cout<<h2[i]<<" ";
    }*/
    vector<set<int> >SS(h2.size()+1);
    int jj=0;
    for(int i=0;i<n;i++){
    	if(HH[i].F==h2[jj]){
    		SS[jj+1].insert(HH[i].S);
    	}
    	else{
    		jj++;
    		SS[jj+1].insert(HH[i].S);
    	}
    }
    vl psum(h2.size()+1);
    psum[0]=0;
    for(int i=1;i<=(h2.size());i++){
    	psum[i]=psum[i-1]+SS[i-1].size();
    }
    for(int i=0;i<k;i++){
    	int aa,bb;
    	cin>>aa>>bb;
    	if(h[bb-1]<h[aa-1])
    	adj[aa].PB(bb);
    	if(h[aa-1]<h[bb-1])
    	adj[bb].PB(aa);
    }
    ll ans;
   /* cout<<"\nSS size.........\n";
    REP(i,0,SS.size()){
    	cout<<SS[i].size()<<" ";
    }
    cout<<"\npsum  ..........\n ";
    REP(i,0,psum.size()){
    	cout<<psum[i]<<" ";
    }
    cout<<"\n";*/
    for(int i=0;i<n;i++){
    	//trace(i);
    	//trace(h[i]);
    	 int ind=lower_bound(h2.begin(),h2.end(),h[i])-h2.begin();
    	 //trace(ind);
    	 ans=psum[ind+1];
    	 ans-=adj[i+1].size();
    	 //trace(psum[ind+1]);
    	 //trace(adj[i+1].size());

    	 if(ans<0)ans=0;
    	 cout<<ans<<" ";
    	 //cout<<"\n\n\n\n";
    }
    cout<<"\n";
    
    return 0;
}