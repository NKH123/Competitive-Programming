#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t, n,g;
    vector<int> v;
    cin>>t;
    while(t--)
    {cin>>n;
    v.resize(n);
    for(int i=0; i<n;i++)
    {
        cin>>v[i];
 
    }
    sort(v.begin(),v.end());
    g=__gcd(v[0],v[1]);
    if(!(n<=2))
    {for(int i=2; i<n;i++)
    g=__gcd(g,v[i]);}
    if(g==1)
    cout<<"0"<<endl;
    else cout<<"-1"<<endl;
 
    }
    return 0;
}