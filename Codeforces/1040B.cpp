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
int n,k;

int main()
{   ios::sync_with_stdio(false);
    cin>>n>>k;
    int no=2*k+1;
    if(n<=(k+1)){
        cout<<1<<"\n"<<"1";
    }
    else{
            int pos;
        int fc=n/no;
        int rem=n%no;
        if(rem==0){
            cout<<fc<<"\n";
            int pos=1+k;
            for(int i=0;i<fc;i++){
                cout<<pos<<" ";
                pos=pos+no;
            }
        }
        else if(rem>=k+1){
            cout<<fc+1<<"\n";
            pos=rem-k;
            cout<<pos<<" ";
            pos=pos+no;
            for(int i=0;i<fc;i++){

                cout<<pos<<" ";
                pos=pos+no;
            }
        }
        else{
            fc--;
            rem=rem+no;
            int first=(k+1);
            int sec=rem-(k+1);
            cout<<fc+2<<"\n";
            int pos=1;
            cout<<pos<<" ";
            pos=pos+no;

            for(int i=0;i<fc;i++){
                cout<<pos<<" ";
                pos=pos+no;
            }

            cout<<pos<<" ";



        }
    }

    return 0;
}
