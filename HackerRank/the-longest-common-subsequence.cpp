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
//int T;

int dp[105][105];
int main(){
    ios::sync_with_stdio(false);
    //cin.tie(NULL);
    //cin>>T;
    int a,b;
    vi s;
    vi t;
   {
        memset(dp,0,sizeof(dp));
        cin>>a>>b;
        s.clear();
        t.clear();
        s.resize(a);
        t.resize(b);
       REP(i,0,a){
           cin>>s[i];
       }
        REP(i,0,b){
            cin>>t[i];
        }
        //cout<<"s="<<s<<"\nt="<<t<<"\n";
        //int l=0;
        for(int i=1; i<=a; i++){
            for(int j=1; j<=b; j++){
                if(s[i-1]==t[j-1]){
                        //cout<<"s["<<i-1<<"]="<<s[i-1]<<" s["<<j-1<<"]="<<s[j-1]<<"\n";
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        /*for(int i=0; i<=a;i++){
            for(int j=0; j<=b; j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<"\n";*/

       // cout<<"max len of LCS="<<dp[a][b]<<"\n";
        int i=a,j=b;
        vi aa;
        aa.clear();
        while(i>=1 && j>=1){
            if(s[i-1]==t[j-1]){
                    //aa=aa+s[i-1];
                aa.PB(s[i-1]);
                i=i-1;
                j=j-1;

            }
            else{
                if(dp[i][j-1]>=dp[i-1][j]){
                    j=j-1;
                }
                else{
                    i=i-1;
                }
            }
        }
        reverse(aa.begin(),aa.end());
        REP(i,0,aa.size()){
            cout<<aa[i]<<" ";
        }
    }

    return 0;
}
