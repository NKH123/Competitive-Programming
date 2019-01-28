#include<bits/stdc++.h>
using namespace std;

int main()
{   ios::sync_with_stdio(false);
    int n;
    cin>>n;
    string t;
    cin>>t;
    int i=1;
    int l=0;
    string S;
    while(l<t.size()){
    	S+=t[l];
    	l=l+i;
    	i++;
    }
    cout<<S<<"\n";
    return 0;
}