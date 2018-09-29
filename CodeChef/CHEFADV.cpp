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
int t;
ll n,m,x,y;
void success(){
    cout<<"Chefirnemo\n";
}
void fail(){
    cout<<"Pofik\n";
}
int main()
{   ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        int f=0;
       cin>>n>>m>>x>>y;
       if((n==1 && m==1)||(n==2 && m==2)){
           success();
           f=1;
           continue;
       }
        ll rema=(n-1)%x;
        ll remb=(m-1)%y;
        if((rema==0 && remb==0)||(rema==1 && remb==1)){
            success();
            f=1;
        }
        else{
            if(x==1 && remb==1 && n!=1){
                success();
                f=1;
            }
            else if(y==1 && rema==1 && m!=1){
                success();
                f=1;
            }

        }
        if(f==0){
            fail();
        }
    }
    return 0;
}
