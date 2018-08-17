#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pb push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <b; i++)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

int main()
{   ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int a=0, b=1023;
    char c;
    int p;
    while(n--)
    {
        cin>>c>>p;
        switch(c)
        {
            case '|': a|=p; b|=p; break;
            case '&': a&=p; b&=p; break;
            case '^': a^=p; b^=p; break;
        }
    }
        int aor=0,aand=1023,axor=0;
        REP(i,0,10)
        {
            int A=a&(1<<i);
            int B=b&(1<<i);
            if(A==0 && B==0)
            {
                aand=aand-(1<<i);
            }
            if(A==0 && B!=0)
            {
                aand=aand|(1<<i);
            }
            if(A!=0 && B==0)
            {
                axor=axor|(1<<i);
            }
            if(A!=0 && B!=0)
            {
                aor=aor^(1<<i);
            }

        }
        cout<<"3\n& "<<aand<<"\n| "<<aor<<"\n^ "<<axor;



    return 0;
}
