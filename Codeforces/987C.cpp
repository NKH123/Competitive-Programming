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
#define llp 1000000007

int main()
{   ios::sync_with_stdio(false);
int fflag=0;
    int prev=0;

    int n;
    cin>>n;
    vi s, c;
    int a;
    int fi,se,th;
    int bflag=0;
     int once=0;
    REP(i,0,n)
    {
        cin>>a;
        s.PB(a);
    }
   
    REP(i,0,n)
    {
        cin>>a;
        c.PB(a);
    }
    int mincost=1<<30;
    int jcost=1<<30,kcost=c[1],lcost=1<<30;

    if(n==3)
    {   //cout<<"In n=3\n";
        if(s[0]>=s[1] || s[1]>=s[2] )
        {  // cout<<"I'm in the first if ";
            //cout<<"Invalid n=3 case\n";
            cout<<-1<<"\n";

        }
        else
        {   //cout<<"Valid n=3 case\n";
            cout<<c[0]+c[1]+c[2]<<"\n";
        }

    }

    else {  //cout<<"In n!=3 case\n";
            se=1;
            for(;se<=n-2;se++)
            {   fflag=0;
            bflag=0;
                kcost=c[se];
                 jcost=1<<30;lcost=1<<30;

//cout<<"In se loop se="<<se<<"\n";
                for(fi=se-1;fi>=0;fi--)
                {
//cout<<"In fi loop fi="<<fi<<"\n";
                    if(s[fi]<s[se])
                    {   jcost=min(jcost,c[fi]);

                       // mincost=min(mincost,c[fi]+c[se]);
//cout<<"Assigned to jcost in if statement jcost="<<jcost<<"\n";
                        bflag=1;
                    }
                }
                for(th=se+1;th<=n-1;th++)
                {  // cout<<"In th loop th="<<th<<"\n";

                    if(s[th]>s[se])
                {

                        lcost=min(lcost,c[th]);
                       // cout<<"Assigned to lcost in if statement lcost="<<lcost<<"\n";
                         bflag=2;

                    /*if(fflag==0 )
                    {
                        mincost=mincost+c[th];
                        cout<<"Assigned to mincost in if statement mincost="<<mincost<<"\n";
                        fflag=1;
                        prev=c[th];

                    }

                   else{
                    //mincost=min(mincost,mincost-prev+c[th]);
                    if(prev>c[th])
                    {
                        mincost=mincost-prev+c[th];
                        cout<<"Assigned to mincost in if statement mincost="<<mincost<<"\n";
                    }*/

                   }
                }

                if(bflag!=0 || bflag!=1)
                {
                    mincost=min(mincost,lcost+jcost+kcost);
                    once=1;
                   // cout<<"Assigned to mincost outside if statement mincost="<<mincost<<"\n";
                }
                }



    if(once==0)
    cout<<"-1";
    else cout<<mincost;
    }
    return 0;
}