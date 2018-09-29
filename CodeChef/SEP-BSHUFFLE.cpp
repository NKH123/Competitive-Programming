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
int n;
int main()
{   ios::sync_with_stdio(false);
    cin>>n;
    if(n==1){
        cout<<"1\n1\n";
    }
    else if(n==2){
        cout<<"1 2\n2 1\n";
    }
    else{
        int I=1;
        vi a(n);
        if(n%2==0){
            a[(n/2)-1]=I;
            I++;
            for(int i=0; i<((n/2)-1);i++){
                a[i]=I;
                I++;
            }
            a[n-1]=I;
            I++;
            for(int i=(n/2);i<(n-1);i++){
                a[i]=I;
                I++;
            }


        }
        else{
            a[(n/2)]=I;
            I++;
            for(int i=0; i<(n/2);i++){
                a[i]=I;
                I++;
            }
            a[n-1]=I;
            I++;
            for(int i=(n/2)+1;i<(n-1);i++){
                    a[i]=I;
                    I++;
            }
        }
        for(int i=0;i<n;i++){
                cout<<a[i]<<" ";
            }
            cout<<"\n";
        for(int i=1; i<=n;i++){
            if(i==1){
                cout<<n<<" ";
            }
            else{
                cout<<i-1<<" ";
            }
        }
        cout<<"\n";
    }
    return 0;
}
