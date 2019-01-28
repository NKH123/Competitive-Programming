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
int a[1005][1005];
bool vt[1005][1005];
ll sum=0;
void dfs(int i,int j,int ai,int bi){
	sum+=a[i][j];
	vt[i][j]=true;
	for(int I=-1;I<=1;I++){
		for(int J=-1;J<=1;J++){
			int aa=i+I;
			int ab=j+J;
			if(aa==i && ab== j)continue;
			else{
				if(!vt[aa][ab] && a[aa][ab]!=0){
					dfs(aa,ab,i,j);
				}
			}
		}
	}
}
string decToBin(int n) 
{ 
    if (n == 0) 
        return "0"; 
      
    // to store the binary equivalent of decimal 
    string bin = "";     
    while (n > 0)     
    { 
        // to get the last binary digit of the number 'n' 
        // and accumulate it at the beginning of 'bin' 
        bin = ((n & 1) == 0 ? '0' : '1') + bin; 
          
        // right shift 'n' by 1 
        n >>= 1; 
    } 
      
    // required binary number 
    return bin; 
} 
int main()
{   ios::sync_with_stdio(false);
    //freopen("a.in", "r", stdin);
    //freopen("b.in", "r", stdin);
    //freopen("c.in", "r", stdin);
    //freopen("d.in", "r", stdin);
    int n,m;
    cin>>n>>m;
    ll ans=0;
    memset(a,0,sizeof(a));
    memset(vt,false,sizeof(vt));
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=m;j++){
    		cin>>a[i][j];
    	}
    }
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=m;j++){
    		if(!vt[i][j] && a[i][j]!=0){
    			dfs(i,j,0,0);
    			ans=max(sum,ans);
    			sum=0;
    		}
    	}
    }
   cout<<decToBin(ans)<<"\n";




    
    return 0;
}