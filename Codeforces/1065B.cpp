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
//freopen("a.in", "r", stdin);
//freopen("b.in", "r", stdin);
//freopen("c.in", "r", stdin);
//freopen("d.in", "r", stdin);
    ll n,m;
    cin>>n>>m;
    ll max,min;
    /*if(m<n/2)
    cout<<n-2*m<<" "<<n-(2+m-1)<<"\n";
    else{
        cout<<n-2*m<<" "<<n<<"\n";
    }*/
    if(n==1){
        cout<<1<<" "<<1<<"\n";
    }
    else{
        if(n==2){
            if(m==0){
                cout<<2<<" "<<2<<"\n";
            }
            else{
                cout<<0<<" "<<0<<"\n";
            }
        }
        else{
            //max

            if(m==0){
                cout<<n<<" "<<n<<"\n";

            }
            else{
                ll M=m;
                M--;
                max=2;
                for(int i=1;i<=(n-2);i++){
                    if(M<=0){
                        break;
                    }
                    max++;
                    M=M-(max-1);
                   /* if(M<=0){
                        break;
                    }*/
                }
                max=n-max;
                M=m;
                min=0;
                if(m>=ceil(n*1.0/2)){
                    min=0;
                }
                else{
                    min=n-2*m;
                }
                cout<<min<<" "<<max<<"\n";
            }

        }
    }


    return 0;
}