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
    long long p,q,b, temp;
    while(n--)
    {
        cin>>p>>q>>b;
        while(( temp=__gcd(p,q))!=1)
        {  // cout<<"In first while gcd of p and q="<<__gcd(p,q)<<"\n";

            p/=temp;
            q/=temp;
            //cout<<"p="<<p<<"q="<<q<<"\n";
        }
        while((b=__gcd(q,b))!=1)
        { //cout<<"In first while gcd of q and b="<<__gcd(q,b)<<"\n";

            q=q/b;
           // b/=temp;
            // cout<<"b="<<b<<"q="<<q<<"\n";
        }
        /*if(q%b==0)
        {
            q=1;
        }*/
        if (q==1)
        cout<<"Finite\n";
        else cout<<"Infinite\n";


    }
    return 0;
}