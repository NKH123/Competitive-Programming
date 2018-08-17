#include<bits/stdc++.h>
#include <initializer_list>
using namespace std;

#define F first
#define S second
#define PB push_back

#define REP(i,a,b) for (int i = a; i <b; i++)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define llp 1000000007
int n, m;
string a;
vi n4,n47,n74,n7,dl;
string q0;
int x,y;
void sp(int si)
{
	swap(n4[si],n7[si]);
	swap(n47[si],n74[si]);
	if(dl[si]==0){
        dl[si]=1;
    }
    else dl[si]=0;
}
void down(int si)
{
    if(!dl[si]){
        return;
    }
    dl[si]=0;
    if(2*si < (1<<21)) sp(2*si);
    if(2*si+1 < (1<<21)) sp(2*si+1);
}
void updt(int si)
{
	down(si);
	n4[si]=n4[2*si]+n4[2*si+1];
    n7[si]=n7[2*si]+n7[2*si+1];
    n47[si]=max({n4[2*si]+n47[2*si+1],n47[2*si]+n7[2*si+1]});
    n74[si]=max({n7[2*si]+n74[2*si+1],n74[2*si]+n4[2*si+1]});
}
void build(int si, int ss, int se){
if(ss==se){
    if(a[ss]=='4'){
        n4[si]=1;
        n7[si]=0;
    }
    else{
        n4[si]=0;
        n7[si]=1;
    }
    n47[si]=1;
    n74[si]=1;
    return;
}
    int mid=(ss+se)/2;
    build(2*si,ss,mid);
    build(2*si+1,mid+1,se);
         updt(si);
}
void Switch(int si,int ss,int se, int us, int ue){
    if(se < us || ue<ss){
        return;
    }
    if(us<=ss && se<=ue ){
    sp(si);
    return;
    }
    int mid=(ss+se)/2;
    down(si);
    Switch(si*2,ss,mid,us,ue);
    Switch(si*2+1,mid+1,se,us,ue);
    updt(si);
}

int main()
{   ios::sync_with_stdio(false);
    cin>>n>>m;
    n4.resize(1<<21);
    n47.resize(1<<21);
    n74.resize(1<<21);
    n7.resize(1<<21);
    dl.resize(1<<21);
    cin>>a;
    build(1,0,n-1);
    /*REP(i,1,2*n){
    cout<<"n47["<<i<<"]="<<n47[i]<<",n4["<<i<<"]="<<n4[i]<<",n74["<<i<<"]="<<n74[i]<<",n7["<<i<<"]="<<n7[i]<<" ";
    }
    cout<<"\n";*/
    while(m--){
        cin>>q0;
        if(q0[0]=='s'){
            cin>>x>>y;
            Switch(1,0,n-1,--x,--y);
        }
        else{
            cout<<n47[1]<<"\n";
        }
    }

    return 0;
}
