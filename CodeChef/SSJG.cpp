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


int a[1005][1005];
int ps[1005][1005];
int fun(int upi,int upj,int doi,int doj){
	ll ans=ps[doi][doj];
	if(upi>0)ans-=ps[upi-1][doj];
	if(upj>0)ans-=ps[doi][upj-1];
	if(upi>0 && upj>0)ans+=ps[upi-1][upj-1];
	return ans;
}
int main()
{   ios::sync_with_stdio(false);
    //freopen("a.in", "r", stdin);
    //freopen("b.in", "r", stdin);
    //freopen("c.in", "r", stdin);
    //freopen("d.in", "r", stdin);
    int t;
    cin>>t;
    while(t--){
    	
    	memset(a,0,sizeof(a));
    	memset(ps,0,sizeof(ps));
    	int n,m;
    	cin>>n>>m;
    	
    	while(m--){
    		int A,B;
    		cin>>A>>B;
    		A--;B--;
    		a[A][B]=1;
    		//ps[A][B]=1;
    	}
    	for(int i=0;i<n;i++){
    		ps[0][i]=a[0][i];
    	}
    	for(int i=1;i<n;i++){
    		for(int j=0;j<n;j++){
    			ps[i][j]=a[i][j]+ps[i-1][j];
    		}
    	}
    
    	
    	for(int i=0;i<n;i++){
    		for(int j=1;j<n;j++){
    			ps[i][j]+=ps[i][j-1];
    		}
    	}
    	
    	
    	int ans=-1;
    	for(int i=1;i<(n-1);i++){
    		for(int j=1;j<(n-1);j++){
    			int ANS=-1;
    			
    			ll l1=fun(0,0,i-1,j-1);

    			ll l2=fun(0,j,i-1,n-1);
    			ll l3=fun(i,0,n-1,j-1);
    			ll l4=fun(i,j,n-1,n-1);
    			ANS=l1;
    			

    			if(ANS>l2)ANS=l2;
    			if(ANS>l3)ANS=l3;
    			if(ANS>l4)ANS=l4;
    			ans=max(ans,ANS);
    		}
    	}
    	cout<<ans<<"\n";



    }
    return 0;
}