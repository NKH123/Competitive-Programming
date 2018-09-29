#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <b; i++)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define llp 1000000007
vector<ll> v,pre;
int main()
{
	ios_base::sync_with_stdio(0);
	ll t,n,m,q,i,j,k,x,y,z;
	cin>>t;
	while(t--)
	{
		cin>>n;
		v.clear();
		pre.assign(n+1,0);
		for(i=1;i<=n;i++)
		{
			cin>>x;
			pre[i]=x+pre[i-1];
			if(x==1)
			v.PB(i);
		}
		m=0;
		if(!v.empty())
		{
			m=max(pre[v[v.size()-1]],pre[n]-pre[v[0]-1]);
		}
		cout<<m+(pre[n]-m)/2<<"\n";
	}

}