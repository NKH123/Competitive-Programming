#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int f=0;
    string S="";
    int start=-1;
    for(int i=1;i<s.size();i++){
        if(s[i]==s[0]){
            
             f=1;
            for(int j=i;j<(s.size());j++){
                if(s[j]!=s[j-i]){
                    f=0;
                    break;
                }
                start=max(j-i,start);



                }
            }
    }
    
            if(f==1){
                    for(int l=start+1;l<n;l++){
                        S=S+s[l];
                    }
                    }
                    if(f==0){
        S=s;
    }


    for(int i=1; i<k;i++){
        s=s+S;
    }
    cout<<s<<"\n";
}
