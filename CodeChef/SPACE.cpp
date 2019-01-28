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

string ord;
vector<string> a;
int Rank( char A){
	for(int i=0;i<26;i++){
		if(A==ord[i]){
			return i;
		}
	}
}
bool comp(string A, string B){
	int l=min(A.size(),B.size());
	int f=0;
	for(int i=0;i<l;i++){
		if(Rank(A[i])!=Rank(B[i])){
			f=1;
			if(Rank(A[i])<Rank(B[i])){
				return true;
			}
			else{
				return false;
			}
		}
	}
	return A.size()<B.size();
}

int main()
{   ios::sync_with_stdio(false);
    //freopen("a.in", "r", stdin);
    //freopen("b.in", "r", stdin);
    //freopen("c.in", "r", stdin);
    //freopen("d.in", "r", stdin);
    int n;
    cin>>n;
    cin>> ord;
    a.resize(n);

    REP(i,0,n){
    	cin>>a[i];
    }
    sort(a.begin(),a.end(),comp);

    for(auto d:a){
    	cout<<d<<" ";
    }
    cout<<"\n";

    
    return 0;
}