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
string s1, s2;
int u=0,d=0;
int main()
{   ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        cin>>s1>>s2;
       // sort(s1.begin(),s1.end());
        //sort(s2.begin(),s2.end());
        int a[123], b[123];
        memset(a,0, sizeof(a));
        memset(b,0,sizeof(b));
        for(auto g:s1){
            a[g]++;
        }
        for(auto g:s2){
            b[g]++;
        }
        int f=1;
        REP(i,0,123){
            if(a[i]>b[i]){
                f=0;
                break;
            }
        }
        if(f==1){
            cout<<"Yes\n";
        }
        else{
            cout<<"No\n";
        }
    }
    return 0;
}