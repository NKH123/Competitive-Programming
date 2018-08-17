#include<bits/stdc++.h>
using namespace std;
int main()
{   ios::sync_with_stdio(false);
 
    vector <int> a;
    vector <int> b;
    int t, n; int A;
    cin>>t;
    while(t--)
    {
        cin>>n;
        a.resize(n);
        for(int i=0; i<n; i++)
       {
 
        cin>>a[i];
        if(i==0)
            A=a[i];
        else A=A^a[i];
       }
 
        cout<<2*A<<endl;
 
    }
    return 0;
}