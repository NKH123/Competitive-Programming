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
int n,d;
vi a,b;
int main()
{   ios::sync_with_stdio(false);
    cin>>n>>d;
    a.resize(n);
    b.resize(n);
    REP(i,0,n){
        cin>>a[i];
    }
    REP(i,0,n){
        cin>>b[i];
    }
    int rank=d;
    int comp=a[d-1]+b[0];
    int l=n-1;
    for(int i=0;i<d-1;i++){
        if(a[i]+b[l]<=comp){
            rank--;
            l--;

        }
    }
    cout<<rank<<"\n";
    return 0;
}