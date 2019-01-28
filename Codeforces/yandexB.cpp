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
 freopen("b.in", "r", stdin);
    int c[10];
    memset(c,0,sizeof(c));
    string s;
    cin>>s;
    vector<int> a;
    int n=s.size();
    a.resize(s.size());
    REP(i,0,n){
        a[i]=s[i]-'0';
    }
   /* cout<<"array is\n";
    REP(i,0,n){
        cout<<a[i]<<" ";
    }
    cout<<"\n";*/
    REP(i,0,n){
        if(i==0){
            c[a[i]]++;

        }
        else{
            if(a[i]!=a[i-1]){
                c[a[i]]++;
            }

        }
    }
    ll ans=1;
   /* REP(i,0,10){
        cout<<c[i]<<" ";
    }
    cout<<"\n";
*/
    REP(i,0,10){
        ans=ans*c[i];
    }
    cout<<ans<<"\n";


    return 0;
}