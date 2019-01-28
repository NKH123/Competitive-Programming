#include<bits/stdc++.h>
using namespace std;
int main(){
  //freopen("b.in", "r", stdin);
    int t;
    //cout<<(1L<<62);
    cin>>t;
    while(t--){
        
        long long p1,p2,k;
        cin>>p1>>p2>>k;
        long long sum=p1+p2;
        sum=sum/k;
        if(sum%2){
            cout<<"COOK\n";
        }
        else{
            cout<<"CHEF\n";
        }
    }
    return 0;
}