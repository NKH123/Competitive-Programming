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
deque <int> a;

int main()
{   ios::sync_with_stdio(false);
    cin>>n>>k;
    int m;
    REP(i,0,n){
        cin>>m;
        a.PB(m);
    }
    int ans=0;
    int f=1,b=1;
    while(a.size()!=0 && (f!=0 || b!=0)){
        if(a.front()<=k && f==1){
            a.pop_front();
            ans++;
        }
        else{
            f=0;
        }
        if(a.size()==0){
            break;
        }
        if(a.back()<=k && b==1){
            a.pop_back();
            ans++;
        }
        else{
            b=0;
        }
    }
    cout<<ans<<"\n";

    return 0;
}
