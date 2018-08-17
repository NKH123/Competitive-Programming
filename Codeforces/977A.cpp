#include<bits/stdc++.h>
using namespace std;

int main()
{   ios::sync_with_stdio(false);
    long long int n;
    int k;
    cin>>n>>k;
    int a;
    while(k--)
    {
        if((n%10)!=0)
        {
            n--;
        }
        else n=n/10;
    }
    cout<<n;
    return 0;
}