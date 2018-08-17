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
int n,m;
long long k;
int a,b,c, count1;
vector<pair<int, pi > > e;
int link[1000001];
int size[1000001];
int find(int x) {
    while (x != link[x]) x = link[x];
    return x;
}
void unite(int a, int b) {
    if (size[a] < size[b])
    swap(a,b);
    size[a] += size[b];
    link[b] = a;
}
int main()
{   ios::sync_with_stdio(false);
    cin>>n>>m>>k;
    while(m--){
        cin>>a>>b>>c;
        e.PB({c,{a,b}});
    }
    sort(e.begin(),e.end());
    REP(i,1,n+1){
        link[i]=i;
        size[i]=1;
    }
    if(k>=n-1)count1=n-1;
    else count1=1<<30;
    for(auto g: e){
        a=g.S.F;
        b=g.S.S;
        c=g.F;
        a=find(a);
        b=find(b);
        if(a!=b){
            unite(a,b);
            n--;
            k=k-c;
            if(k>=n-1){
                count1=n-1;
            }
        }
    }
    if(n>1||count1>((1<<30)-1))
    count1=-1;
    cout<<count1<<"\n";
    return 0;
}
