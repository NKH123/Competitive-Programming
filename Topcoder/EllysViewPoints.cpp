#include<bits/stdc++.h>
using namespace std;
class EllysViewPoints{
public:
    int getCount(int N, int M, vector <string> s){
        vector<vector<int> >U(N,vector<int>(M,0));
        vector<vector<int> >D(N,vector<int>(M,0));
        vector<vector<int> >L(N,vector<int>(M,0));
        vector<vector<int> >R(N,vector<int>(M,0));
        int ans=0;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(i==0 && s[i][j]=='.'){
                    U[i][j]=1;
                }
                else{
                    if(s[i][j]=='.'){
                        if(s[i-1][j]=='.' && U[i-1][j]==1){
                            U[i][j]=1;
                        }
                    }
                }
            }
        }
        for(int i=N-1;i>=0;i--){
            for(int j=0;j<M;j++){
                if(i==N-1){
                    if(s[i][j]=='.'){
                        D[i][j]=1;
                    }
                }
                else{
                    if(s[i][j]=='.'){
                        if(s[i+1][j]=='.' && D[i+1][j]==1){
                            D[i][j]=1;
                        }
                    }
                }
            }
        }
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(j==0){
                    if(s[i][j]=='.'){
                        L[i][j]=1;
                    }
                }
                else{
                    if(s[i][j]=='.'){
                        if(s[i][j-1]=='.' && L[i][j-1]==1){
                            L[i][j]=1;
                        }
                    }
                }
            }
        }
        for(int i=0;i<N;i++){
            for(int j=M-1;j>=0;j--){
                if(j==M-1){
                    if(s[i][j]=='.'){
                        R[i][j]=1;
                    }
                }
                else{
                    if(s[i][j]=='.'){
                        if(s[i][j+1]=='.' && R[i][j+1]==1){
                            R[i][j]=1;
                        }
                    }
                }
            }
        }
        
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(L[i][j]==1 && R[i][j]==1 && U[i][j]==1 && D[i][j]==1){
                    ans++;
                }
            }
        }
        return ans;
    }
};
