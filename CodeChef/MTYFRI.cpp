#include<bits/stdc++.h>
using namespace std;
int main()
{   ios::sync_with_stdio(false);
    int h,n,k,M=0,T=0,f,K=0;
    int mt, tt;
    int m[10000],t[10000];
    cin>>h;
    while(h--)
    {
        cin>>n>>k;
        f=0; K=1; M=0; T=0;
        for(int i=0; i<n;i++)
        {
            if(!(i%2))
            {
                cin>>m[i/2];
                M=M+m[i/2];
            }
            else {cin>>t[i/2];
            T=T+t[i/2];}}
            //cout<<"M="<<M<<endl<<"T="<<T<<endl;
            if(T>M)
            {
                f=1;
            }
            if(n%2)
            {sort(m,m+((n/2)+1));mt=(n/2);}
            else {sort(m,m+(n/2)); mt=(n/2)-1;}
            sort(t,t+(n/2));
            tt=0;
 
            while((f!=1)&&(K<=k))
            {
                M=M-m[mt]+t[tt];
                T=T-t[tt]+m[mt];
                if(T>M)
                f=1;
 
 
                // cout<<"Loop no."<<K<<  "In loop M="<<M<<endl<<"In Loop T="<<T<<endl;
                 K++;
                mt--;
                if(tt==((n/2) -1))
                    break;
                tt++;
            }
 
 
if(f==1)
            cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
 
        }
 
 
 
    return 0;
}
 