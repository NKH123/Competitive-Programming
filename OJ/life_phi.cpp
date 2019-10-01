#include <bits/stdc++.h>
using namespace std;
#define int long long 

const int MAX=1e6+49;

long long phi[1000050]{0}; 

void computeTotient() 
{ 
    int n=MAX;
    for (int i=1; i<=n; i++) 
        phi[i] = i; 
  
    for (int p=2; p<=n; p++) 
    { 
        if (phi[p] == p) 
        { 
            phi[p] = p-1; 
  
            for (int i = 2*p; i<=n; i += p) 
            { 
               phi[i] = (phi[i]/p) * (p-1); 
            } 
        } 
    } 
    for(int i=1;i<=MAX;i++){
        phi[i]+=phi[i-1];
    }
} 

signed main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin>>q;
    computeTotient();
    while(q--){
        int u,v;
        cin>>u>>v;
            cout<<phi[v]-phi[u-1]<<endl;
    }
    
    return 0;
}



