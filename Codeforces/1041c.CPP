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
ll m;
ll d;
int main()
{   ios::sync_with_stdio(false);
    cin>>n>>m>>d;
    vi a;
    set<pair<int, int> > A;
    a.resize(n);
    //A.resize(n);
    REP(i,0,n){
        cin>>a[i];
        A.insert({a[i],i});
    }
    //sort(A.begin(),A.end());
    vi days;
    days.resize(n);
    int day=0;
    while(A.size()!=0){
       day++;
        days[A.begin()->S]=day;
        int ps=A.begin()->S;
        A.erase(A.begin());
        while(A.size()!=0){
            auto y=A.lower_bound({a[ps]+d+1,0});
            if(y==A.end()){
                break;
            }
            days[y->S]=day;
            ps=y->second;
            A.erase(y);

        }
        
    }
    cout<<day<<"\n";
    for(int i=0; i<n;i++){
        cout<<days[i]<<" ";
    }
    cout<<"\n";
    return 0;
}