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
vector<pair<int,int> >a[100005];
bool vt[100005];
ll ans=0;
int s;
void dfs(int x){
	vt[x]=true;
	ans++;
	for(auto g:a[x]){
		if(!vt[g.F] && g.S<=s ){
			dfs(g.F);
		}
	}
} 
int main()
{   ios::sync_with_stdio(false);
    freopen("a.in", "r", stdin);
    //freopen("b.in", "r", stdin);
    //freopen("c.in", "r", stdin);
    //freopen("d.in", "r", stdin);
    int n,m;
    cin>>n>>m;
    memset(vt,false,sizeof(vt));
    while(m--){
    	int A,B,C;
    	cin>>A>>B>>C;
    	A--;
    	B--;
    	a[A].PB({B,C});
    	a[B].PB({A,C});


    }
    int k;
    cin>>k;
 
    cin>>s;
    vi b;
    while(k--){
    	int x;
    	cin>>x;
    	x--;
    	b.PB(x);
    }
    for(int i=0;i<b.size();i++){
    	if(!vt[b[i]]){
    		dfs(b[i]);
    	}
    }
    cout<<ans<<"\n";
    
    return 0;
}