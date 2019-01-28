#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <b; i++)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define llp 1000000007

int main()
{   ios::sync_with_stdio(false);
    //freopen("a.in", "r", stdin);
    //freopen("b.in", "r", stdin);
    //freopen("c.in", "r", stdin);
    //freopen("d.in", "r", stdin);
    int n;
    cin>>n;
    vi a;
    a.resize(n);
    REP(i,0,n){
    	cin>>a[i];
    }
    /*int N=n/2;
    if(n%2==0)N--;
    int fl=N;
    /*if(n%2==0){
    	N--;
    }
    int fl=0;
    int sum=0;
    do{
    	sum=sum+a[fl];
    	fl++;
    }while(sum<(n/2) && fl<n);
    fl--;
    int ans=0;*/
    //cout<<"fl="<<fl<<"\n";
    int ans=0;
    REP(i,0,n){
    	ans+=a[i]*2*2*i;
    }
    cout<<ans<<"\n";


    return 0;
}