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
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vi a;
        a.resize(n);
        REP(i,0,n)cin>>a[i];
        int f=0;
        int pos=0;
        REP(i,1,n){
            if(a[i]<a[i-1]){
                f++;
                //pos=i-1;
            }
        }

        if(f>1 ){
            cout<<"NO\n";
        }
        else{
            if(f==0){
                cout<<"YES\n";
            }
            else{
                if(a[0]>=a[a.size()-1]){
                    cout<<"YES\n";
                }
                else{
                    cout<<"NO\n";
                }

            }
        }


    }

    return 0;
}