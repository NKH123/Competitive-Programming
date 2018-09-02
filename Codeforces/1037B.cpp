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
int n,s;
vi a;
int main()
{   ios::sync_with_stdio(false);
    cin>>n>>s;
    a.resize(n);
    REP(i,0,n){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    int mid=n/2;
    ll ans=0;
    if(n==1){
        ans=abs(a[mid]-s);
    }
    else if(a[mid]==s){
        ans=0;
    }
    else{
        if(a[mid]<s){
            int r=mid+1;
            while(a[r]<s && r<n){
                ans=ans+(s-a[r]);
                a[r]=s;
                r++;
            }
            ans=ans+s-a[mid];
        }
        else{
            int l=mid-1;
            while(a[l]>s && l>=0){
                ans=ans+(a[l]-s);
                a[l]=s;
                l--;
            }
            ans=ans+a[mid]-s;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
