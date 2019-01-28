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
    int n,k;
    cin>>n>>k;
    vi a;
    a.resize(n);
    REP(i,0,n){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    int K=k;
    int i=0;
    int diff=0;
    while(k--){
        while(a[i]-diff==0){
            i++;
            
        }
        if(i!=n){
        cout<<a[i]-diff<<"\n";
        diff=diff+a[i]-diff;
        }
        else{
           cout<<0<<"\n";
        }


    }

    return 0;
}