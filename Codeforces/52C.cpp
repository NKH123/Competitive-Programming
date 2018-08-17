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
int n,m,lf,rg,v, ans;
vi a;
vi mini(800009);
vi val(800009);
char buff[50];
void build(int x,int l,int r){
    if(l==r){
        mini[x]=a[l];
        val[x]=a[l];
        return;
    }
    val[x]=0;
    int mid=(l+r)/2;
    build(2*x,l,mid);
    build(2*x+1,mid+1,r);
    mini[x]=min(mini[2*x],mini[2*x+1])+val[x];
}
void add(int x,int l, int r, int lf, int rg, int v){
    if(lf<=l && rg>=r){
        val[x]=val[x]+v;
        mini[x]=mini[x]+v;
        return;
    }
    int mid=(l+r)/2;
    if(lf<=mid){
        add(2*x,l,mid,lf,rg,v);
    }
    if(rg>mid){
        add(2*x+1,mid+1,r,lf,rg,v);
    }
    mini[x]=min(mini[2*x],mini[2*x+1])+val[x];
}
int query(int x, int l, int r, int lf, int rg){
    if(lf<=l && rg>=r){
        return mini[x];
    }
    int mid=(l+r)/2;
    int ret=1<<30;
    if(lf<=mid){
        ret=min(ret,query(2*x,l,mid,lf,rg));
    }
    if(rg>mid){
        ret=min(ret,query(2*x+1,mid+1,r,lf,rg));
    }
    ret+=val[x];
    return ret;
}
int main()
{   //ios::sync_with_stdio(false);
    
    cin>>n;
    REP(i,0,n){
        int A;
        cin>>A;
        a.PB(A);
    }

    build(1,0,n-1);
    cin>>m;
    getchar();
    while(m--){
        gets(buff);
       // string S=buff;
        int cs=0;
        for(int i=0; buff[i]!='\0';i++){
            if(buff[i]==' '){
                cs++;
            }
        }
        //cout<<"buff=";
        //puts(buff);
        //cout<<"spaces="<<cs<<"\n";
        if(cs==2){
            sscanf(buff,"%d %d %d",&lf,&rg,&v);
            if(rg<lf){
                add(1,0,n-1,lf,n-1,v);
                add(1,0,n-1,0,rg,v);
            }
            else{
                add(1,0,n-1,lf,rg,v);
            }
        }
        else{
            sscanf(buff,"%d %d",&lf,&rg);
        if(rg<lf){
            ans=query(1,0,n-1,lf,n-1);
            ans=min(ans,query(1,0,n-1,0,rg));
        }
        else{
            ans=query(1,0,n-1,lf,rg);
        }
        cout<<ans<<"\n";
        }

    }
    return 0;
}
