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
#define First get<0>
#define Second get<1>
#define Third get<2>
int n,x,y;
//const int N=(int)sqrt(1000000000)+10;
string q0;
vi h;
int tree[1000000];
vector<tuple<string,int,int> > Q;
set<int> B[250000];
void mod(int si,int ss,int se,int tr,int X){
    if(ss==se){
        tree[si]=X;
        return;
    }
    int mid=(ss+se)/2;
    if(tr<=mid){
        mod(2*si,ss,mid,tr,X);
    }
    else{
        mod(2*si+1,mid+1,se,tr,X);
    }
    tree[si]=max(tree[2*si],tree[2*si+1]);
}
int query(int si,int L,int R, int l, int r){
    if(l<=L && R<=r){
        return tree[si];
    }
    int mid=(L+R)/2;
    int val=-1;
    if(l<=mid){
        val=max(val,query(2*si,L,mid,l,r));
    }
    if(mid<r){
        val=max(val,query(2*si+1,mid+1,R,l,r));
    }
    return val;
}


int main()
{   ios::sync_with_stdio(false);
    cin>>n;
    REP(i,0,n){
        cin>>q0>>x>>y;
        Q.push_back(make_tuple(q0,x,y));
        if(q0!="find"){
            h.PB(x);
        }
    }
    sort(h.begin(),h.end());
    auto et=unique(h.begin(),h.end());
    h.erase(et,h.end());
    //tree.resize(1000000);
    fill(tree,tree +1000000,-1);
    REP(i,0,n){
        x=Second(Q[i]);
        y=Third(Q[i]);
        if(First(Q[i])!="find"){
            int lb=lower_bound(h.begin(),h.end(),x)-h.begin();
            if(First(Q[i])=="add"){
                B[lb].insert(y);
            }
            else{
                B[lb].erase(y);
            }
            if(B[lb].size()==0){

                mod(1,0,h.size()-1,lb,-1);
            }
            else{
                auto X=(B[lb].end());
                X--;
                mod(1,0,h.size()-1,lb,*X);
            }
        }
        else{
            int ub=upper_bound(h.begin(),h.end(),x)-h.begin();
            int l=ub,r=h.size()-1,tr=h.size();
            while(l<=r){
                int mid=(l+r)/2;
                if(query(1,0,h.size()-1,ub,mid)>y){
                    tr=mid;
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
            if(tr==h.size()){
                cout<<"-1\n";
            }
            else{
                int Y=*B[tr].upper_bound(y);
                cout<<h[tr]<<" "<<Y<<"\n";
            }
        }

    }

    return 0;
}
