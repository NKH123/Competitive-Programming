#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define REP(i,a,b) for (int i = a; i <b; i++)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define llp 1000000007
int t;
long long n;
 
 
int main()
{   ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        cin>>n;
        if(__builtin_popcount(n)==2){
            cout<<0<<"\n";
        }
        else if(__builtin_popcount(n)==1){
                if(n==1){
                cout<<"2\n";
                 }
                else{
                cout<<"1\n";
                }
 
            }
        else{
            int no=32-__builtin_clz(n);
            if(n&(1<<(no-2))){
                long long diff=0;
                int pos=no-2;
                diff=min(n-(1<<(pos))-(1<<(no-1)),(1<<(no-2))-(n-(1<<(pos))-(1<<(no-1)))+1);
                cout<<diff<<"\n";
            }
            else{
                long long diff=0;
                int pos=no-3;
                for(;pos>=0;pos--){
                    if(n&(1<<(pos))){
                        diff=min(n-(1<<(pos))-(1<<(no-1)),(1<<(pos))-(n-(1<<(pos))-(1<<(no-1))));
                        break;
                    }
                }
                cout<<diff<<"\n";
 
 
            }
        }
    }
 
    return 0;
}
 