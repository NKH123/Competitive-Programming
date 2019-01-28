#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> a;
    a.resize(n);
    for(int i=0;i<n;i++)
    cin>>a[i];
    long long  rem=0;
    long long ans=0;
    ll prev=0;
    for(int i=0;i<n;i++){
        rem=rem+a[i];
        ans=ans+rem/k;
        rem=rem%k;
    }
    if(rem!=0){
        ans++;
    }
    cout<<ans<<"\n";

    return 0;
}