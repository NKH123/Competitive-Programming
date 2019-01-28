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
set<pair<pair<int,int >,pair<int ,int > > > SS;

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
set<int> s;
void print(vi a){
	REP(i,0,a.size()){
		cout<<a[i]<<" ";
	}
	cout<<"\n";
}
int capa=1000;
 vi ba;
    vi bb;
    vi trace;
int capb=1000;
void process(int n){
	vi BA(ba);
	vi BB(bb);

	if(n==5){
		s.insert(capa);
		/*for(auto d:trace){
			cout<<d<<" ";

			
		}
		cout<<"\n";*/
		SS.insert({{trace[0],trace[1]},{trace[2],trace[3]}});
	}
	else{
		if(n%2){
			for(int i=0;i<10;i++){
				//trace(n);
				//print(ba);
				//print(bb);
				int t=ba[i];
				int te=capa;
				int tE=capb;
				capa=capa-ba[i];
				capb=capb+ba[i];
				trace.PB(ba[i]);
				bb.PB(ba[i]);
				ba.erase(ba.begin()+i);
				//ba.erase(i);
				process(n+1);
				//bb.erase(bb.begin()+bb.size()-1);
				//ba.insert(ba.begin()+i,ba[i]);
				bb=BB;
				ba=BA;//bb(BB);
				//ba(BA);
				capa=te;
				capb=tE;
				trace.pop_back();
			}
		}
		else{
			for(int i=0;i<11;i++){
				//trace(n);
				//	print(ba);
				//print(bb);
				int te=capa;
				int tE=capb;
				capb=capb-bb[i];
				capa=capa+bb[i];
				ba.PB(bb[i]);
				trace.push_back(bb[i]);
				bb.erase(bb.begin()+i);
				//bb.erase(i);
				process(n+1);
				//ba.erase(ba.begin()+ba.size()-1);
				//bb.insert(bb.begin()+i,bb[i]);
				bb=BB;
				ba=BA;
				capa=te;
				capb=tE;
				trace.pop_back();
			}
		}
	}
}

int main()
{   ios::sync_with_stdio(false);
   freopen("backforth.in", "r", stdin);
    freopen("backforth.out", "w", stdout);
    //freopen("c.in", "r", stdin);
    //freopen("d.in", "r", stdin);
   
    ba.resize(10);
    bb.resize(10);
    REP(i,0,10){
    	cin>>ba[i];
    }
    REP(i,0,10){
    	cin>>bb[i];
    }

    process(1);
  /*  for(auto d:SS){
    	cout<<d.F.F<<" "<<d.F.S<<" "<<d.S.F<<" "<<d.S.S<<"\n";
    }
    cout<<"\n";
    for(auto d:s){
    	cout<<d<<" ";
    }
    cout<<"\n";*/
    cout<<s.size()<<"\n";
    return 0;
}