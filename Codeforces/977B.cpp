#include<bits/stdc++.h>
using namespace std;

int main()
{   ios::sync_with_stdio(false);
int n;
    cin>>n;
    string s;
    cin>>s;
    char a, b;
    int I=0;
    int count=0;
    int ind=0;
    for(int i=0; i<(s.size() - 1); i++)
    {count=0;
        a=s[i];
        b=s[i+1];
        for(int j=0;j<(s.size() - 1);j++)
        {
            if(s[j]==a && s[j+1]==b)
            {
                count++;
            }
            if(count>I)
            ind=i;
            I=max(count,I);
        }

    }
    cout<<s[ind]<<s[ind+1];
    return 0;
}