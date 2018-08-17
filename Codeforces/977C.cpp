#include<bits/stdc++.h>
using namespace std;

int main()
{   ios::sync_with_stdio(false);

   int n, k;
   cin>>n>>k;
   vector<int> v;
   v.resize(n);
   for(int i=0; i<n; i++)
   {
       cin>>v[i];
   }
   sort(v.begin(), v.end());
   if(v[k-1]==v[k])
   {
       cout<<"-1";
   }
   else cout<<v[k-1];
    return 0;
}