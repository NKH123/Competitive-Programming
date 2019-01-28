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
/*bool comp(vector<pi > a, vector <pi > b){
	return a.S<b.S;
}
bool comp1(vector<pi > a, vector <pi > b){
	return a.F<b.F;
}*/
vector<int>a[2*(100000)+5];
int main()
{   ios::sync_with_stdio(false);
    //freopen("a.in", "r", stdin);
    //freopen("b.in", "r", stdin);
    //freopen("c.in", "r", stdin);
    //freopen("d.in", "r", stdin);
   	int n;
   	cin>>n;
   	vector<pair<int, int> >p;
   	vector<pair<int, int> >q;
   	REP(i,0,n){
   		int A,B;
   		cin>>A>>B;
   		if(A>B){
   			swap(A,B);
   		}

   		p.PB({A,B});
   		if(A<B){
   			swap(A,B);
   		}
   		q.push_back({A,B});
   	}
   	sort(p.begin(),p.end());
   	sort(q.begin(),q.end());
   	vector<int>ans(n);
   	ans[0]=1;
   	ans[1]=p[0].S;
   	ans[n-1]=p[1].S;
   	/*cout<<"Before\n";
   	REP(i,0,n){
   		cout<<ans[i]<<" ";
   	}
   	cout<<"\n";*/
   	for(int i=2;i<n-1;i++){
   		int ele=ans[i-1];
   		int lele=ans[i-2];
   		int aa=ele;
   		int bb=lele;
   		int f=0;
   		if(aa<bb){
   			//swap(aa,bb);
   			//f=1;

   			pair<int,int> pp={aa,bb};
   		auto aaa=lower_bound(p.begin(),p.end(),pp)-p.begin();
   		//trace(aaa);
   		
   			if(aaa!=(n-1)){
   				if(p[aaa+1].F==pp.F){
   					if(pp.S!=p[aaa+1].S)
   					//ans.PB(p[aaa+1].S);
   				ans[i]=p[aaa+1].S;
   					else{
   						//ans.PB(p[aaa].S);
   						ans[i]=p[aaa].S;
   					}
   				}
   				else{
   					if(pp.S!=p[aaa-1].S)
   					//ans.PB(p[aaa-1].S);
   				ans[i]=p[aaa-1].S;
   					else{
   						//ans.PB(p[aaa].S);
   						ans[i]=p[aaa].S;

   					}
   				}
   			}
   		
   		}
   		else if(aa>bb){
   			pair<int,int> pp={aa,bb};
   		auto aaa=lower_bound(q.begin(),q.end(),pp)-q.begin();
   		
   		//trace(aaa);
   			if(aaa!=(n-1)){
   				if(q[aaa+1].F==pp.F){
   					if(pp.S!=q[aaa+1].S)
   					//ans.PB(q[aaa+1].S);
   					ans[i]=q[aaa+1].S;
   					else{
   						//ans.PB(q[aaa].S);
   						ans[i]=q[aaa].S;
   					}
   				}
   				else{
   					if(pp.S!=q[aaa-1].S)
   					//ans.PB(q[aaa-1].S);
   				ans[i]=q[aaa-1].S;
   					else{
   						//ans.PB(q[aaa].S);
   						ans[i]=q[aaa].S;
   					}
   				}
   			}

   		}
   		
   		

   	}
   /*	REP(i,0,n){
   		cout<<ans[i]<<" ";
   	}*/
   	for(int i=n-1;i>=0;i--){
   		cout<<ans[i]<<" ";
   	}
   	cout<<"\n";

   	return 0;
    
    //return 0;
}