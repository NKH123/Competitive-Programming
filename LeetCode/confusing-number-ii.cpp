#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int>no;
    vector<int>val{0,1,6,8,9};
    vector<int>NN;
    int solve(int pos,int small){
        if(pos==no.size()){
            vi Nn;
            Nn.clear();
            Nn.resize(NN.size());
            for(int i=0;i<NN.size();i++){
                Nn[i]=NN[i];
            }
            reverse(Nn.begin(),Nn.end());
            while(Nn.size()>0 && Nn[(int)Nn.size()-1]==0){
                Nn.pop_back();
            }
            reverse(Nn.begin(),Nn.end());
            int prev=0;
            for(int i=0;i<Nn.size();i++){
                prev=prev*10+Nn[i];
            }
            int nex=0;
            for(int i=(int)(Nn.size())-1;i>=0;i--){
                if(Nn[i]!=6 && Nn[i]!=9)
                    nex=nex*10+Nn[i];
                else{
                    if(Nn[i]==6){
                        nex=nex*10+9;
                    }
                    else{
                        nex=nex*10+6; 
                    }
                }
            }
            if(prev!=nex){
                return 1;
            }
            else{
                return 0;
            }
        }
        else{
            int ans=0;
            if(small==1){
                for(int i=0;i<5;i++){
                    NN.push_back(val[i]);
                    ans+=solve(pos+1,1);
                    NN.pop_back();
                }
            }
            else{
                for(int i=0;i<5;i++){
                    if(no[pos]>val[i]){
                        NN.push_back(val[i]);
                        ans+=solve(pos+1,1);
                        NN.pop_back();
                    }
                    else if(no[pos]==val[i]){
                        NN.push_back(val[i]);
                        ans+=solve(pos+1,0);
                        NN.pop_back();
                    }
                }
            }
            return ans;
        }
    }

    int confusingNumberII(int N) {
        int n=N;
        while(n>0){
            no.push_back((n%10));
            n=n/10;
        }
        reverse(no.begin(),no.end());
        int ct=solve(0,0);
        return ct;
    }
};