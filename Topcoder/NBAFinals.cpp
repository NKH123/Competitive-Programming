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
};