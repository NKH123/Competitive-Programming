#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<int> arr(n+1,0);
    int q;
    int rt=sqrt(n);
    int s=0;
    vector<unordered_map<int,vector<pair<int,int>>>> v(rt+1);
    int cd[325][n+1];
    for(int i=1;i<sqrt(n);i++){
        for(int j=1;j<=n;j++){
            int k=(j%i);
            v[i][k].push_back(make_pair(j,0));
            cd[i][j]=v[i][k].size()-1;
        }
    }
    
    
    // int bb[325][n+1];
    // for(int i=1;i<rt;i++){
    //     for(int j=1;j<=n;j++){
    //         int k=j%i;
    //         bb[i][k]=j;
    //     }
    // }
    
    cin>>q;
    while(q--){
        int a,b;
        cin>>a>>b;
        int k=b%a;
        
        if(a>=rt){
            for(int i=0;i*a+b<=n;i++){
                arr[i*a+b]++;
            }
        }
        else{
            int ans=cd[a][b];
            v[a][k][ans].second++;
        }
    }
    for(int i=1;i<rt;i++){
        for(auto j: v[i]){
            vector<pair<int,int>> c=j.second;
            for(int l=0;l<c.size();l++){
                if(l){
                    c[l].second+=c[l-1].second;
                    arr[c[l].first]+=c[l].second;
                }
                else{
                    arr[c[l].first]+=c[l].second;
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}


