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
deque<int> a;
deque<int> d;
int main()
{   ios::sync_with_stdio(false);
cin>>n;
    for(int i=0; i<n;i++){
        int A,B;
        cin>>A>>B;
        a.PB(A);
        d.PB(B);
    }
    sort(a.begin(),a.end());
    sort(d.begin(),d.end());
    int ans=0;
    int count=0;
    for(int i=0;i<2460;i++){
        if(i>=a.front()){
            a.pop_front();
            count++;
        }
        if(i>=b.front()){
            d.pop_front();
            count--;
        }
        ans=max(ans,count);
    }
    cout<<ans<<"\n";

    return 0;
}