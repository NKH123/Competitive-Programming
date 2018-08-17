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
vi a[1000001];
vi ch;
int count1=0;
void findch(int s, int p){
        ch[s]=0;
        for(auto g:a[s]){
            if(g!=p){
            findch(g,s);
            if(ch[g]!=-1)ch[s]+=1+ch[g];
            }
        }
}
void dfs(int s, int p){
    for(auto g: a[s]){
        if(g==p)continue;
        if(ch[g]%2)count1++;
        dfs(g,s);
    }
}
int main()
{   ios::sync_with_stdio(false);
    int f,s;
    cin>>n;
    REP(i,0,n-1){
        cin>>f>>s;
        a[f].PB(s);
        a[s].PB(f);
    }
    if(n%2)cout<<-1<<"\n";
    else{
    ch.resize(n+1);
    fill(ch.begin(),ch.end(),-1);
    findch(1,0);
    dfs(1,0);
    cout<<count1<<"\n";
    }
    return 0;
}
