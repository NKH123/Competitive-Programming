#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define REP(i,a,b) for (int i = a; i <b; i++)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define llp 1000000007
int n;
long long m;
vi a,b,c;


int main()
{   ios::sync_with_stdio(false);
    cin>>n>>m;
    a.resize(n);
    b.resize(n);
    c.resize(n);
    long long sum=0;
    long long sum1=0;
    REP(i,0,n){
        cin>>a[i]>>b[i];
        c[i]=a[i]-b[i];
        sum1=sum1+b[i];
        sum=sum+a[i];
    }
    if(sum1>m){
        cout<<"-1"<<"\n";
    }
    else{
    sort(c.begin(),c.end());

    int count1=0;
    for(int i=c.size()-1;i>=0;i--){
        if(sum<=m){

            break;
        }
        else{
            sum=sum-c[i];
            count1++;
        }
    }



        cout<<count1<<"\n";

    }
    return 0;
}