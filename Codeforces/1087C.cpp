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

int x[3],y[3];
int fv,fh,sv,sh,tv,th;
ll sum=1LL<<30;
int Start=0, mid=0,End=0;
void fsmall(int a,int b,int c){
	//int FV,FH,SV,SH,TV,TH=0;
	int FV=abs(y[a]-y[b]);
	int FH=abs(x[a]-x[b]);
	int SV=abs(y[b]-y[c]);
	int SH=abs(x[b]-x[c]);
	ll prevsum=sum;
	sum=min(sum,(ll)(FV+FH+SV+SH));
	if(sum!=prevsum){
		fv=FV;
		fh=FH;
		sv=SV;
		sh=SH;
		Start=a;
		mid=b;
		End=c;

	}

}
void ppath(int a,int b,int c,int d){
	cout<<a<<" "<<b<<"\n";
	if(c>=a){
	for(int i=a+1;i<=c;i++){
		cout<<i<<" "<<b<<"\n";
	}
}

else{
	for(int i=a-1;i>=c;i--){
		cout<<i<<" "<<b<<"\n";
	}
}
if(d>=a){
	for(int i=b+1;i<=d;i++){
		cout<<c<<" "<<i<<"\n";
	}
}
else{
	for(int i=b-1;i>=d;i--){
		cout<<c<<" "<<i<<"\n";
	}
}
}
int main()
{   ios::sync_with_stdio(false);
    //freopen("a.in", "r", stdin);
    //freopen("b.in", "r", stdin);
    //freopen("c.in", "r", stdin);
    //freopen("d.in", "r", stdin);
    //int xa,xb,xc,ya,yb,yc;
    cin>>x[0]>>y[0];
    cin>>x[1]>>y[1];
    cin>>x[2]>>y[2];

    int fv,fh,sv,sh,tv,th;
    fsmall(0,1,2);
    fsmall(0,2,1);
    fsmall(1,0,2);
    fsmall(1,2,0);
    fsmall(2,0,1);
    fsmall(2,1,0);
    cout<<sum+1<<"\n";
    trace(Start);
    trace(mid);
    ppath(x[Start],y[Start],x[mid],y[mid]);
    ppath(x[mid],y[mid],x[End],y[End]);

    




    
    return 0;
}