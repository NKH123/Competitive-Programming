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
string a,b;

int main()
{   ios::sync_with_stdio(false);
    cin>>a>>b;

    int ans=0;
    //int ans=(unsigned)abs(a.size()-b.size());
    int ap=a.size()-1;
    int bp=b.size()-1;
    while(ap>=0 && bp>=0){
        if(a[ap]==b[bp]){
            ap--;
            bp--;
        }
        else{
            break;
        }
    }
    ans=bp+ap+2;
    cout<<ans<<"\n";
    return 0;
}