#include<bits/stdc++.h>
using namespace std;



int32_t main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;;
    while(t--){
        string s;
        cin>>s;
        int n=s.size();
        string left="";
        for(int i=1;i<s.size();i++){
            left+=s[i];
        }
        left+=s[0];
        string right="";
        right+=s[n-1];
        for(int i=0;i<(n-1);i++){
            right+=s[i];
        }
        if(left==right){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }

    return 0;
}