#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string>T;
    map<int,vector<char>>M;
    int Ssize;
    string SS;
    vector<char>sss;
    void brute(int ct){
        if(ct==Ssize){
            string s;
            for(int i=0;i<sss.size();i++){
                s=s+sss[i];
            }
            T.push_back(s);
        }
        else{
            if(ct==0){
                sss.clear();
            }
            for(auto g:M[ct]){
                sss.push_back(g);
                brute(ct+1);
                sss.pop_back();
            }
        }
    }
    
    vector<string> permute(string S) {
        Ssize=0;
        int ct=0;
         for(int i=0;i<S.size();i++){
            if(S[i]=='{'){
                i++;
                while(S[i]!='}'){
                    if(S[i]!=','){
                        M[ct].push_back(S[i]);   
                    }
                    i++;
                }
                Ssize++;
                
            }
            else{
                M[ct].push_back(S[i]);
                Ssize++;
            }
             ct++;
        }
        SS=S;
        brute(0);
        sort(T.begin(),T.end());
        return T;
    }
};