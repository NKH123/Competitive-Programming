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

int main()
{   ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	vl a(n);
	REP(i,0,n)cin>>a[i];
	//vi c(n);
	vector<pair<ll,ll > >cc;
    set<pair<ll,ll> >CC;
	map<ll,ll>c;
	vl C;
	REP(i,0,n){
		ll A;
		cin>>A;
		//c.PB({A,i});
		C.PB(A);
		c[A]=i;
		cc.PB({A,i});
        CC.insert({A,i});
	}
	sort(cc.begin(),cc.end());
	vl t(m);
	vl d(m);
	REP(i,0,m){
		cin>>t[i]>>d[i];
		t[i]--;
	}
	//ll ans=0;
    REP(i,0,m){
   
    	ll ans=0;
    	if(a[t[i]]>=d[i]){
    		
    		a[t[i]]-=d[i];
    		ans+=d[i]*C[t[i]];

    	}
    	else{
    		ll ANS=0;
    		ANS+=a[t[i]]*C[t[i]];
   
    		ll don=a[t[i]];
    		ll rem=d[i]-a[t[i]];
    		a[t[i]]=0;

    			for(auto g:CC){

    				if(a[g.S]==0)continue;
    				else{
    					if(a[g.S]>=rem){	
    					//	cout<<"here1\n";
    						a[g.S]-=rem;
    						ANS+=(rem*C[g.S]);
    					//	trace(C[g.S]);
    						rem=0;
                            if(a[g.S]==0){
                                CC.erase({g.F,g.S});
                            }
    					}
    					else{
    						//cout<<"here2\n";
    						ANS+=a[g.S]*C[g.S];
    						rem-=a[g.S];
    						a[g.S]=0;
                            if(a[g.S]==0){
                                CC.erase({g.F,g.S});
                            }
    						//trace(C[g.S]);
    						//trace(ANS);


    					}
    					if(rem==0){
    						break;
    					}
    				}
    			}
    //			cout<<"out loop\n";
    			if(rem>0){
    				//cout<<0<<"\n";
    			}
    			else{
    				//ans+=ANS;
    				ans=ANS;
    				//cout<<ans<<"\n";
    			}
    		
    	}
    	cout<<ans<<"\n";
    }
    //cout<<ans<<"\n";
    return 0;
}