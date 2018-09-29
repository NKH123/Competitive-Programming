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
int n,s,j;
int main()
{   ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        cin>>n;
        int ans=0;
        while(n--){
            cin>>s>>j;
            if((j-s)>5){
                ans++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}