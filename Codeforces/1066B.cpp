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
int n,r;
cin>>n>>r;
vi a;
a.resize(n);
REP(i,0,n){
    cin>>a[i];
}
vi b(n);
int start=0;
int f=0;
for(int i=start;i<r;i++){
    if(a[i]==1){
        f=1;
        start=i;
    }
}
if(f==1){
    cout<<-1<<"\n";
}



    return 0;
}