#include<bits/stdc++.h>
using namespace std;
int32_t main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int a, b, c;
        cin>>a>>b>>c;
        int q=c/a;
        if(c%a==0 && b!=0){
            q--;
        }
        int ans=(a*q)+b;
        cout<<ans<<"\n";
    }

    return 0;
}