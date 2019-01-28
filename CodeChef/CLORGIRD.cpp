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
int a[1005][1005];
bool check(int i,int j){
    if(a[i][j]!=1 && a[i+1][j]!=1 && a[i+1][j+1]!=1 && a[i][j+1]!=1){
        return true;
    }
    else{
        return false;
    }
}
void paint(int i,int j){
    a[i][j]=2;
    a[i+1][j]=2;
    a[i+1][j+1]=2;
    a[i][j+1]=2;
}
int main()
{   ios::sync_with_stdio(false);
    //freopen("a.in", "r", stdin);
    //freopen("b.in", "r", stdin);
    //freopen("c.in", "r", stdin);
    //freopen("d.in", "r", stdin);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<string>s;
        s.resize(n);
        REP(i,0,n){
            cin>>s[i];
            for(int j=0;j<m;j++){
                if(s[i][j]=='.'){
                    a[i][j]=0;
                }
                else{
                    a[i][j]=1;
                }
            }
        }
        for(int i=0;i<n-1;i++){
            for(int j=0;j<m-1;j++){
                if(check(i,j)){
                    paint(i,j);
                }
            }
        }
        int f=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j]!=1 && a[i][j]!=2){
                    f=0;
                    break;
                }
                if(f==0){
                    break;
                }
            }
        }
        if(f==0){
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n";
        }

    }

    return 0;
}