#include<bits/stdc++.h>
using namespace std;



class NBAgain{ 
public:
 int dubsAgain(vector <int> scores, string team){
    int W=0,R=0;
    for(int i=0;i<team.size();i++){
        if(team[i]=='W'){
            if(scores[i]==0){
                W+=4;
            }
            else{
                W+=scores[i];
            }
        }
        else if(team[i]=='R'){
            if(scores[i]==0){
                R+=1;
            }
            else{
                R+=scores[i];
            }
        }
        else{
            if(scores[i]==0){
                W+=4;
            }
            else{
                W+=scores[i];
            }
        }
    }
    if(W>R){
        return 1;
    }
    else{
        return 0;
    }
}
int dubsAgain1(vector <int>L, string S){
    int W=0;
    int R=0;
    for(int i=0;i<S.size();i++){
        if(L[i]==0){
            if(S[i]!='R'){
                W+=4;
            }
        }
        else if(S[i]=='?'){
            if(L[i]==0){
                W+=4;
            }
            else{
                W+=L[i];
            }
        }
        else{
            if(S[i]=='R'){
                R+=L[i];
            }
            else{
                W+=L[i];
            }
        }
    }
    if(W>R){
        return 1;
    }
    else{
        return 0;
    }

}
};

int main(){
    NBAgain N;
    cout<<N.dubsAgain({0,0,0,0,4},"RRRRW")<<"\n";
    cout<<N.dubsAgain1({0,0,0,0,4},"RRRRW")<<"\n";
    return 0;
}