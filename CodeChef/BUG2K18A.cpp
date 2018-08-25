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
int t,n,r;
vi a;
int main()
{   ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        cin>>n>>r;
        a.clear();
        a.resize(n);
        REP(i,0,n){
            cin>>a[i];
        }
        sort(a.begin(),a.end());
        int count=0;
        for(auto g:a){
            if(g<=r){
                count++;
            }
            else{
                break;
            } 
        }
        cout<<n<<" "<<count<<" "<<count<<"\n";
    }
    return 0;
}