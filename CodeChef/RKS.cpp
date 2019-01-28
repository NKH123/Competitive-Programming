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
#define print(x) cout<<#x<<" is "; for(int i=0;i<x.size();i++){cout<<x[i]<<" ";}cout<<"\n"
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
bool row[1000006];
bool col[1000006];
int main()
{   ios::sync_with_stdio(false);
    //freopen("a.in", "r", stdin);
    //freopen("b.in", "r", stdin);
    //freopen("c.in", "r", stdin);
    //freopen("d.in", "r", stdin);
    int t;
    cin>>t;
    int n,k;

    while(t--){
    	cin>>n>>k;
    	memset(row,false,sizeof(row));
    	memset(col,false,sizeof(col));
    	while(k--){
    		int A,B;
    		cin>>A>>B;
    		row[A]=true;
    		col[B]=true;
    	}
    	int i=1,j=1;
    	int ct=0;
    	vector<pair<int,int> > pa;
    	pa.clear();
    	while(i<=n && j<=n){
    		while(row[i]==true){
    			i++;
    		}
    		while(col[j]==true){
    			j++;
    		}
    		if(i>n || j>n)break;
    		pa.PB({i,j});
    		row[i]=true;
    		col[j]=true;
    		i++;
    		j++;
    	}
    	cout<<pa.size()<<" ";
    	for(auto g:pa){
    		cout<<g.F<<" "<<g.S<<" ";
    	}
    	cout<<"\n";
    }
    return 0;
}