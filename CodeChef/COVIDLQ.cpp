#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;




int32_t main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    vi a;
    while(t--){
        int n;
        cin>>n;
        a.resize(n);
        int ans=1e9;
        int prev=-(1e9);
        int f=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(a[i]==1 && f==0 ){
                f=1;
                prev=i;
            }
        }
        int P=prev;
        for(int i=prev+1;i<n;i++){
            if(a[i]==1){
                ans=min(ans,i-P);
                P=i;
            }
        }
        if(ans<6){
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n";
        }


    }

    return 0;
}