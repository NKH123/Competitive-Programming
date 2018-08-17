#include<bits/stdc++.h>
using namespace std;

int main()
{   ios::sync_with_stdio(false);
    string s;
    cin>>s;
    int p=0,l=0;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='o')
        p++;
        if(s[i]=='-')
        l++;
    }
    if(l==0||p==0)
    {
        cout<<"YES";
    }
    else if(p==1)
    {
        cout<<"YES";
    }
    else if(l%p==0)
    {
        cout<<"YES";
    }
    else cout<<"NO";

    return 0;
}