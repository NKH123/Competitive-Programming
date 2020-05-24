#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll arr0[1000][1000];
ll arr1[1000][1000];

ll min(ll a, ll b){
    if(a<=b)
     return a;

    return b;
}


ll dp(int n1, int n2, int k1, int k2, int start){

    if(n1<0 || n2<0){
        return 0;
    }

    if(n1==0 || n2==0){

        if(n1==0){
            if(n2>k2)
                return 0;

            else
                return 1;
        }

        if(n2==0){
            if(n1>k1)
                return 0;

            else
                return 1;

        }
    }

    if(start ==0){
        //cout<<n1<<" "<<n2<<" "<<arr0[n1][n2]<<" "<<start<<endl;
        if(arr0[n1][n2]!=-1)
            return arr0[n1][n2];

        else{
            ll tot = 0;
            for (int i=1; i<=k1; i++) {
                tot+= dp(n1-i, n2, k1, k2, 1);
            }
         
            arr0[n1][n2] = tot;
            return tot;
        }
    }

    else{
        if(arr1[n1][n2]!=-1)
            return arr1[n1][n2];

        else{
            ll tot = 0;
            for (int i=1; i<=k2; i++){
            }
            arr1[n1][n2] = tot;
            return tot;
        }


    }
     
     
}
int main(){
    int n,m,k;
    cin>>n>>m>>k;

    char ch[n+1][m+1];
    for(int i=0;i<n;i++){
        for(int  j=0;j<m;j++){
            cin>>ch[i][j];
        }
    }
     
    int answer[n+1][m+1]{0};
    int visited[n][m]{0};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int ans=0;
            vector<pair<int,int>> v;
            if(visited[i][j])continue;
            if(ch[i][j]!='*'){
                // Do bfs
                queue<pair<int,int>> q;
                q.push(make_pair(i,j));
                while(!q.empty()){
                    pair<int,int> top=q.front();
                    q.pop();
                    if(ch[top.first][top.second]=='*')ans++;
                    if(visited[top.first][top.second])continue;
                    v.push_back(top);
                    if(ch[top.first][top.second]=='*')ans=ans;
                    else{
                        if(top.first<n-1)
                        q.push(make_pair(top.first+1,top.second));
                        if(top.first>=1)
                        q.push(make_pair(top.first-1,top.second));
                        if(top.second>=1)
                        q.push(make_pair(top.first,top.second-1));
                        if(top.second+1<m);
                        q.push(make_pair(top.first,top.second+1));
                    }
                    visited[top.first][top.second]=1;
                }
            }
            for(auto l:v){
                answer[l.first][l.second]=ans;
            }
        }
    }
    while(k--){
        ll c,d;
        cin>>c>>d;
        c--;
        d--;
        cout<<answer[c][d]<<endl;
    }
}
