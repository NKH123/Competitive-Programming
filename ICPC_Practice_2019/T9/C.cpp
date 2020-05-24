#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MOD 1000000007
//vector <int>
// push_back
// char ice[n][m];
char ice [505][505];
int vis[505][505];
ll n, m;

ll max(ll a, ll b){
    if(a>=b)
        return a;

    return b;
}

bool getPath(ll x1, ll y1, ll x2, ll y2){
    //cout<<"%"<<x1<<" "<<y1<<endl;
    if(x1>=n || x1<0 || y1>=m || y1<0)
        return false;

    if(x1==x2 && y1==y2){
        return true;
    }

    if(vis[x1][y1]==1)
        return false;

    // ice[x1][y1] = 'X';
    vis[x1][y1]=1;

    if(getPath(x1+1,y1,x2,y2))
        return true;

    if(getPath(x1,y1+1,x2,y2))
        return true;

    if(getPath(x1-1,y1,x2,y2))
        return true;

    if(getPath(x1,y1-1,x2,y2))
        return true;

    return false;

}

bool getValid(ll x1, ll y1){
    if(x1>=n || x1<=0 || y1>=m || y1<0)
        return false;

    if(ice[x1][y1]=='X')
        return false;

    return true;
}

int main(){

ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>ice[i][j];
        }
    }

    ll x1, y1, x2, y2;

    cin>>x1>>y1>>x2>>y2;
    x1--;
    y1--;
    x2--;
    y2--;
    memset(vis,0,sizeof(vis));
    ice[x1][y1]='.';
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==x1 && j==y1)continue;
            if(ice[i][j]=='X'){
                vis[i][j]=1;
            }
        }
    }
    if(x1==x2 && y1==y2){
        int f=0;
            if(x2!=0){
                if(ice[x2-1][y2]=='.'){
                    f++;
                }
            }

            //left
            if(y2!=0){
                if(ice[x2][y2-1]=='.'){
                    f++;
                }
            }

            //right
            if(y2!=m){
                if(ice[x2][y2+1]=='.'){
                    f++;
                }
            }
            //down
            if(x2!=n){
                if(ice[x2+1][y2]=='.'){
                    f++;
                }
            }
            if(f>=1){
                cout<<"YES\n";
            }
            else{
                cout<<"NO\n";
            }
    }

    else if(getPath(x1, y1, x2, y2)){
        //ice[x1][y1] ='X';

        if(ice[x2][y2]=='X' ){
            cout<<"YES\n";
        }

        else{
            //top
            int f=0;
            if(x2!=0){
                if(ice[x2-1][y2]=='.'){
                    f++;
                }
            }

            //left
            if(y2!=0){
                if(ice[x2][y2-1]=='.'){
                    f++;
                }
            }

            //right
            if(y2!=m){
                if(ice[x2][y2+1]=='.'){
                    f++;
                }
            }
            //down
            if(x2!=n){
                if(ice[x2+1][y2]=='.'){
                    f++;
                }
            }
            if(f>=2){
                cout<<"YES\n";
            }
            else{
                cout<<"NO\n";
            }
        }
    }
    else{
        cout<<"NO\n";
    }

}



