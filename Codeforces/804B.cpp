#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <b; i++)
#define LI 1000000007
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;


int main()
{   ios::sync_with_stdio(false);
    string s;
    cin>>s;
    while(s[0]=='b')
    {
        s.erase(0,1);
    }
    while(s[s.size()-1]=='a')
    {
        s.erase(s.size()-1,1);
    }
    int ans=0;
    int countb=0;
    int ind=s.size()-1;
    label:
    for(int i=s.size()-1;i>=0;i--)
    {
        if(s[i]=='b')
        {
            countb++;
        }
        else
        {
            ans=(ans%LI+countb%LI)%LI;
            countb=(2*(countb%LI))%LI;
            s.erase(i,s.size()-i);
            goto label;
        }
    }
    cout<<ans;


    return 0;
}

 
 
