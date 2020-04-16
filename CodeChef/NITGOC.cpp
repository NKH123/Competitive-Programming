#include<bits/stdc++.h>
using namespace std;



int32_t main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int x, y;
        cin>>x>>y;
        while(x!=y && x>0 && y>0) {
            if(x<y){
                swap(x,y);
            }
            int q=x/y;
            if(x%y==0){
                q--;
            }
            x=x-q*y;

        }
        if(x==y && x!=1){
            cout<<"NO\n";
        }
        else{
            if(x==y && x==1){
                cout<<"YES\n";
            }
            else{
                cout<<"NO\n";
            }
        }
    }

    return 0;
}