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
bool nl(char a){
	if(a==' ' || a=='\t'){
		return true;
	}
	return false;
}

int main()
{   ios::sync_with_stdio(false);
    //freopen("a.in", "r", stdin);
    //freopen("b.in", "r", stdin);
    //freopen("c.in", "r", stdin);
    //freopen("d.in", "r", stdin);
    int t;
    cin>>t;
    if(nl('a')&&nl('&')){
    	cout<<"works\n";
    }
   // int a;
   // cin>>a;
    cin.ignore();
    while(t--){
    string s;
    //cin>>s;
    getline(cin,s);
   //trace(s);
    int f=0;
    if(s.size()<3){
    	cout<<"regularly fancy\n";
    	continue;
    }
    for(int i=0;i<s.size()-2;i++){
    	if(s[i]=='n'){
    		if(i!=0 and !nl(s[i-1]))
    			continue;
    		if(s[i+1]=='o'){
    			if(s[i+2]=='t'){
    				if((i+2)!=(s.size()-1)){
    					if(nl(s[i+3])){
    						cout<<"Real Fancy\n";
    						f=1;
    						break;

    					}
    				}
    				else{
    					cout<<"Real Fancy\n";
    						f=1;
    						break;
    				}
    			}
    		}

    	}
    }
    if(f==1)continue;
    cout<<"regularly fancy\n";
	}	

    
    return 0;
}