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
    if(n%2){
        REP(i,0,n-1){
            cout<<1<<" ";
        }
        cout<<n<<"\n";
    }
    else{
        if(n!=2){
        REP(i,0,n-2){
            cout<<1<<" ";
        }
        cout<<2<<" "<<n<<"\n";
        }
        else{
            cout<<"1 2\n";
        }
    }
    return 0;
}