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
    int t;
    //vi a;
    //vi ps;
    int a[100005];
    int ps[100005];
    cin>>t;
    int n;
    while(t--){
        cin>>n;
        //a.resize(n);
        //ps.resize(n);
        REP(i,0,n){
            cin>>a[i];
        }
        ps[0]=a[0];
        REP(i,1,n){
            ps[i]=a[i]+ps[i-1];
        }
        int day=0;
        int pt=0;
        int count=0;
        while(pt<(n-1)){
            pt=pt+ps[pt];
            day++;
            /*if(count>100000){
                break;
            }
            count++;*/
        }
        cout<<day<<"\n";
    }

    return 0;
}