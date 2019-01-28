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
 int a[100009][26];
int main()
{   ios::sync_with_stdio(false);
    //freopen("a.in", "r", stdin);
    //freopen("b.in", "r", stdin);
    //freopen("c.in", "r", stdin);
    //freopen("d.in", "r", stdin);
    int t;
    cin>>t;
   

    while(t--){
    	int n;
    	string s;
    	cin>>n>>s;
    	memset(a,0,sizeof(a));
    	for(int i=0;i<s.size();i++){
    		int A=s[i]-'a';

    		for(int j=0;j<26;j++){
    			a[i+1][j]=a[i][j];
    		}
    		a[i+1][A]++;
    	}
    	int i=1;
    	int j=s.size();
    	int B[26];
    	int f=0;
    	int ans=0;
    	for(int len=s.size();len>3;len--){
    		int i=1;
    		int j=i+len-1;
    	while(j<=(s.size())){
    		
    		memset(B,0,sizeof(B));
    		for(int I=0;I<26;I++){
    			B[I]=a[j][I]-a[i-1][I];
    			if(B[I]>=(j-i+1)/2){
    				f=1;
    				break;
    			}
    		}
    		if(f==1){
    			ans=j-i+1;
    			break;
    		}
    		i++;
    		j++;
    		
    	}
    	if(f==1){
    		break;
    	}
    }
    	if(f==1){
    		cout<<ans<<"\n";
    	}
    	else{
    		cout<<3<<"\n";
    	}

    }
    
    return 0;
}