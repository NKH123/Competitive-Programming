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
vi aa;
int getno(int x){
	int ret=0;
	REP(i,0,aa.size()){
		if(aa[i]%x==0){
			ret++;
		}
	}
	return ret;
}
int getNo(int x, int y){
	int ret=0;
	REP(i,0,aa.size()){
		if(aa[i]%x==0 && aa[i]%y==0){
			ret++;
		}
	}
	return ret;
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
		int N,a,b;
		cin>>N>>a>>b;
		aa.resize(N);
		REP(i,0,N){
			cin>>aa[i];
		}
		int al=0,bo=0;
		al=getno(b);
		int comm=getNo(a,b);
		bo=getno(a);

    	/*if(a>b){
    		if(a%b==0){
    			if(al>0){
    				if(al==bo){
    					cout<<"BOB\n";
    				}
    				else{
    					cout<<"ALICE\n";
    				}
    			}
    			else{
    				cout<<"ALICE\n";
    			}
    		}
    		else{
    			bo-=comm;
    			al-=comm-1;
    			if(al==bo){
    				//if(__gcd(a,b)==1)
    				cout<<"ALICE\n";
    				//else{

    				//}
    			}
    			else{
    				if(al>bo){
    					cout<<"ALICE\n";
    				}
    				else{
    					cout<<"BOB\n";
    				}
    			}
    		}
    	}
    	else if(a<b){
    		if(b%a==0){
    		if(bo>0){
    			if(al==bo){
    				cout<<"BOB\n";
    			}
    			else{
    				cout<<"BOB\n";
    			}
    		}
    		else{
    			cout<<"ALICE\n";
    		}
    		}
    		else{
    			bo-=comm;
    			al-=comm-1;
    			if(al==bo){
    				cout<<"ALICE\n";
    			}
    			else{
    				if(al>bo){
    					cout<<"ALICE\n";
    				}
    				else{
    					cout<<"BOB\n";
    				}
    			}
    		}
    	}*/
		if(a==b){
			if(bo>0){
				cout<<"BOB\n";
			}
			else{
				cout<<"ALICE\n";
			}

		}
		else{
			if(comm==0){
				if(bo<=al){
					cout<<"ALICE\n";
				}
				else{
					cout<<"BOB\n";
				}

			}
			else{
				bo=bo-comm;
				al=al-comm-1;
				if(al<0){
					cout<<"BOB\n";
				}
				else{
					if(bo==0){
						cout<<"ALICE\n";
					}
					else{
						if(bo<=al){
							cout<<"ALICE\n";
						}
						else{
							cout<<"BOB\n";
						}
					}
				}
			}
		}

	}

	return 0;
}