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
int n;
vi a;

int main()
{   ios::sync_with_stdio(false);
    cin>>n;
    a.resize(n);
    REP(i,0,n){
        cin>>a[i];
    }
    long long ans=0;
    int l=0;
    long long sl=a[0];
    int r=n-1;
    long long sr=a[n-1];
    while(l<r){
        if(sl==sr){
            ans=max(ans,sl);
            l++;
            sl+=a[l];
        }
        else if(sl<sr){
            l++;
            sl+=a[l];
        }
        else if(sl>sr){
            r--;
            sr=sr+a[r];
        }
    }
    cout<<ans<<"\n";


    return 0;
}