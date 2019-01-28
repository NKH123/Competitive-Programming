#include<bits/stdc++.h>
using namespace std;

int main()
{   ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int a[(1e5)+5];
    int maxi=-1;
    int mini=1e6;
    for(int i=0;i<n;i++){
    	cin>>a[i];
    	maxi=max(a[i],maxi);
    	mini=min(a[i],mini);

    }
    sort(a.begin(),a.end());
    cout<<min(a[n-1]-a[1],a[n-2]-a[0])<<"\n";
    /*int maxx=-1;
    REP(i,0,n){
    	if(a[i]!=)
    }*/

    
    return 0;
}