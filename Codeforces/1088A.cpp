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
    int x;
    cin>>x;
    int a=-1,b=-1;
    for(int i=1;i<=x;i++){
        for(int j=1;j<=x;j++){
            if(i%j==0 && i*j >x && i/j<x ){
                a=i;
                b=j;
                break;
            }
        }
    }
    if(a==-1 && b==-1){
        cout<<-1;
    }
    else{
        cout<<a<<" "<<b<<"\n";
    }


    return 0;
}