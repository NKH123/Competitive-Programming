#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <b; i++)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

int main()
{   ios::sync_with_stdio(false);
    int n;
    cin>>n;
    string s;
    cin>>s;
    char status;
    int gap=0;
    int f=1;
    if(n==1)
    {
        if(s[0]=='1')
            cout<<"Yes";
        else
            cout<<"No";
    }
    else{
    REP(i,0,n)
    {
        if(s[i]=='1')
        {if( gap<=2)
            gap=0;

            if(!(gap<=2)||status=='1')
           {

               f=0;
               break;
           }
           status='1';

        }
        if(s[i]=='0')
        {
            gap++;
            status='0';
        }
        if((s[n-2]=='0'&&s[n-1]=='0')||(s[0]=='0'&&s[1]=='0'))
        {

            f=0;
            break;
        }

    }
    if(f==1)
    cout<<"Yes";
    else cout<<"No";}
    return 0;
}
