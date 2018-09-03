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
int n,pos,l,r,Pos;

int main()
{   ios::sync_with_stdio(false);
    cin>>n>>Pos>>l>>r;
    int ans=0;
    if(l==1 &&  r==n){
        cout<<0<<"\n";
    }
    else{
        int lf=0,rf=0;
        pos=Pos;
        if(l>1){
            lf=abs(pos-l);
            //lf=lf*2;
            pos=l;
           // rf=abs(r-l);
            lf++;
            //rf++;
        }
        if(r<n){
            lf+=abs(pos-r);
            //rf+=2*abs(pos-r);
            lf++;
            //rf++;
        }
        pos=Pos;
        if(r<n){
            rf=abs(pos-r);
            pos=r;
            rf++;
        }
        if(l>1){
            rf+=abs(pos-l);
            rf++;
        }
        cout<<min(lf,rf);

    }

    return 0;
}
