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
map<int,int> m;
if(m.find(0)==m.end()){
    cout<<"True\n";
}
    int t;
    ll L,v,l,r;
    cin>>t;
    while(t--){
        cin>>L>>v>>l>>r;
        ll no=L/v;
        //cout<<"no="<<no<<"\n";
        ll len=l-r;
        //no=no-(r-l)/v;
        ll left=l/v;
        if(l%v==0){
            left--;
        }
        ll right=r/v;
        no=no-(right-left);
        cout<<no<<"\n";

    }

    return 0;
}