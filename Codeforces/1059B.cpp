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
int n,m;    
char a[1005][1005];
 int b[1005][1005];
 bool check(int p,int q){
     /*REP(i,0,n){
        REP(j,0,m){
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }*/
     //cout<<"p="<<p<<" q="<<q<<"\n";
     if(p>(n-3) || q>(m-3)){
         //cout<<"I'm here0\n";
         return false;
     }
     else{
         for(int i=0; i<3;i++){
             //cout<<"i="<<i<<"\n";
             if(a[p][q+i]!='#'){
                 //cout<<"p="<<p<<"m+i="<<m+i<<"\n";
                // cout<<a[p][m+i]<<"\n";
                // cout<<"I'm here1\n";
                   return false;
             }
             
             if(a[p+i][q]!='#'){
                // cout<<"I'm here2\n";
                 return false;
             }
             
             if(a[p+2][q+i]!='#'){
                // cout<<"I'm here3\n";
                 return false;
             }
             
             if(a[p+i][q+2]!='#'){
                 //cout<<"I'm here4\n";
                 return false;
             }
            
         }
         for(int i=0; i<3;i++){
             b[p][q+i]=1;
             b[p+i][q]=1;
             b[p+i][q+2]=1;
             b[p+2][q+i]=1;
         }
         return true;
     }
 }
int main()
{   ios::sync_with_stdio(false);
    cin>>n>>m;
    
    REP(i,0,n){
        REP(j,0,m){
            cin>>a[i][j];
        }
    }
    /*REP(i,0,n){
        REP(j,0,m){
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }*/
   
    memset(b,0,sizeof(b));
    for(int i=0; i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]=='#'){
                if(b[i][j]==0){
                    bool B=check(i,j);
                    if(B==false){
                        cout<<"NO\n";
                       // cout<<"I'm here\n";
                        return 0;
                    }
                }
                else{
                    bool B=check(i,j);
                    //if(B==)
                }
            }
        }
    }
    for(int i=0; i<n;i++){
        for(int j=0; j<m;j++){
            if(a[i][j]=='#' && b[i][j]!=1){
                cout<<"NO\n";
                return 0;
            }
        }
    }
    cout<<"YES\n";
    return 0;
}