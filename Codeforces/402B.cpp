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

int fun(vector<int> a,int k,int m)
{
    int count=0;
    if(!(a[0]==m)){
        a[0]=m;
        count++;
    }
    REP(i,1,a.size())
    {
        if(!(a[i]==(a[i-1]+k)))
        {

            count++;
        }
        a[i]=a[i-1]+k;
    }
    return count;
}

int main()
{   ios::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    vi b(n);
    int minu=1<<30;
    int first;
    REP(i,0,n)
    cin>>b[i];
    REP(i,1,1001)
    {
       int temp=fun(b,k,i);
       if(temp<minu)
       {
           minu=temp;
           first=i;
       }
    }
    cout<<minu<<"\n";
    REP(i,0,b.size())
    {
        if(i==0)
        {
            if(b[i]>first)
            {
                cout<<"- "<<i+1<<" "<<b[i]-first<<"\n";
            }
            if(b[i]<first)
            {
                cout<<"+ "<<i+1<<" "<<first-b[i]<<"\n";
            }
            b[i]=first;
        }
        else{
            if(b[i]>(b[i-1]+k))
            {
                cout<<"- "<<i+1<<" "<<b[i]-(b[i-1]+k)<<"\n";
            }
            if(b[i]<(b[i-1]+k))
           {
               cout<<"+ "<<i+1<<" "<<(b[i-1]+k)-b[i]<<"\n";
            }
            b[i]=(b[i-1]+k);
        }
    }
    return 0;
}
