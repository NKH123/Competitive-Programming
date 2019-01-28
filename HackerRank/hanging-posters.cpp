#include<bits/stdc++.h>
using namespace std;


int n,k,a[10007];

int main(){
    cin>>n>>k;
    for(int i=0;i<k;i++){
        cin>>a[i];
    }   
    double lo = 0.0, hi = 1e15, mid; //lo is time? hi is time??
    for(int i = 0; i < 400; i++){ // no. of iteraions??
        mid = (lo+hi)/2; 
        int inv = n;       // no. of invaders
        double req = 0.0; 
        for (int j = 0; j < k; j++) 
          if(a[j] >= mid){ 
            inv--; 
          }else{ 
            req += a[j];   // what is req??
          } 
        if(inv <= 0){
            lo = mid; 
            continue;
        } 
        req /= inv; 
        if (req < mid) hi = mid; else lo = mid; 
    } 

    cout<<fixed<<setprecision(9)<<mid<<endl;
}

