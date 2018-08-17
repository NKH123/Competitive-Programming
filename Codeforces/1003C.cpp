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
int n,k;
vi a;
vector<double> ps;
int main()
{   ios::sync_with_stdio(false);
    cin>>n>>k;
    a.resize(n+1);
    ps.resize(n+1);
    ps[0]=0;
    REP(i,1,n+1){
        cin>>a[i];
        ps[i]=ps[i-1]+a[i];
    }
    double ans=0;
    double temp=0;
    for(int I=k;I<=n;I++){
    for(int i=1; i<=(n-I+1);i++ ){
        temp=0;
        /*for(int j=0;j<I;j++){
            temp=temp+(double)a[i+j]/(double)(I);
        }*/
        temp=(double)(ps[i+I-1]-ps[i-1])/double(I);
        ans=max(ans,temp);
    }
    }
    printf("%.9f",ans);
    return 0;
}
