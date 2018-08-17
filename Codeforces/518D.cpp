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
int n,t;
double p;
double f[2002][2002];
double fun(int n, int t){
    if(t==0){
        return 0;
    }
    if(n==0){
        return 0;
    }
    if(!isnan(f[n][t])){
        return f[n][t];
    }
    else{ 
        return f[n][t]=(1-p)*fun(n,t-1)+p*(fun(n-1,t-1)+1);
    }
}
int main()
{   ios::sync_with_stdio(false);
    cin>>n>>p>>t;
    memset(f,-1,sizeof(f));
    if(n>=t)
    cout<<p*t;
    else{
        //cout<<fun(n,t);
        printf("%0.9f",fun(n,t));
    }
    return 0;
}
