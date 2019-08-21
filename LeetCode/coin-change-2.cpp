#include<bits/stdc++.h>
using namespace std;
#define deb(x) cerr << #x << " = " << x << endl;
class Solution {
public:
    vector<int>a;
    int fun(int N, int I){
        if(I==0){
            if(N==0)return 1;
            else return 0;
        }
        else{
            int ans=0;
            for(int i=0;;i++){
                if(N<i*a[I])break;
                ans+=fun(N-i*a[I],I-1);
            }
            return ans;
        }
    }
    int change(int amount, vector<int>& coins) {
        a=coins;
        int ans=fun(amount,coins.size());
        return ans;
    }
};