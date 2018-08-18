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
vi a;
vi b;
vi previ;
int main()
{   ios::sync_with_stdio(false);
    cin>>n;
    a.resize(n);
    REP(i,0,n)cin>>a[i];
    vi c(n+1);
    vi dp(n+1);
    int sz = 1;
c[1] = a[0]; 
dp[0] = 1;
for( int i = 1; i < n; i++ ) {
   if( a[i] < c[1] ) {
      c[1] = a[i];
      dp[i] = 1;
   }
   else if( a[i] > c[sz] ) {
      c[sz+1] = a[i];
      dp[i] = sz+1;
      sz++;
   }
   else {
      int k = lower_bound( c.begin(), c.begin()+sz, a[i] )-c.begin(); 
      dp[i] = k;
   }
}
cout<<sz<<"\n";
    return 0;
}
