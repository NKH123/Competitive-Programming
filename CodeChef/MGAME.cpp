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


int main()
{   ios::sync_with_stdio(false);
    //freopen("a.in", "r", stdin);
    //freopen("b.in", "r", stdin);
    //freopen("c.in", "r", stdin);
    //freopen("d.in", "r", stdin);
    int t;
    int n,p;
    cin>>t;
    while(t--){
    	cin>>n>>p;
    	int maxi=-1;
    	int I,J,K;
    	int ans;
    	for(int i=1;i<=p;i++){
    		for(int j=1;j<=p;j++){
    			for(int k=1;k<=p;k++){
    				ans=(((n%i)%j)%k)%n;
    				if(ans>maxi){
    					maxi=ans;
    					I=i;
    					J=j;
    					K=k;
    				}
    			}
    		}
    	}
    	//trace(maxi);
    	//trace(I);
    	//trace(J);
    	//trace(K);
        ll count=0;

    	for(int i=1;i<=p;i++){
    		for(int j=1;j<=p;j++){
    			for(int k=1;k<=p;k++){
    				ans=(((n%i)%j)%k)%n;
    				if(ans==maxi){
    	//				cout<<"I="<<i<<" J="<<j<<" K="<<k<<"\n";
                        count++;
    				}
    			}
    		}
    	}
        trace(count);
    }
    
    return 0;
}