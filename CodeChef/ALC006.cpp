#include<bits/stdc++.h>
using namespace std;
#define ll long long


class node{
  public:
    ll sz;
    map<ll,ll> my;
    ll el;
    node(){
        my.clear();
        sz=0;
        el=-1;
    }
};

node merge_(node a,node b){
    node c;
    map<ll,ll> t;
    for(auto i:a.my){
        t[i.first]+=i.second;
    }
    for(auto i:b.my){
        t[i.first]+=i.second;
    }
    for(auto i:t){
        if(c.sz<i.second){
            c.sz=i.second;
            c.el=i.first;
        }
    }
    c.my=t;
    return c;
}

void build(node *T ,ll *a,ll si,ll ei,ll i){
    if(si>ei){
        return ;
    }
    if(si==ei){
        node t;
        map<ll,ll> tt;
        t.my[a[si]]++;
        t.el=a[si];
        t.sz++;
        T[i]=t;
        return ;
    }
    ll mid=(si+ei)/2;
    build(T,a,si,mid,2*i);
    build(T,a,mid+1,ei,2*i+1);
    T[i]=merge_(T[2*i],T[2*i+1]);
}

node query(node *T,ll si,ll ei,ll l,ll r,ll i){
    if(si>ei || ei<l || si>r){
        node t;
        return t;
    }
    if(si>=l && ei<=r){
        return T[i];   
    }
    ll mid=(si+ei)/2;
    return merge_(query(T,si,mid,l,r,2*i),query(T,mid+1,ei,l,r,2*i+1));
}

int main() {

    ll n;
    cin>>n;
    ll a[n];
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    ll k;
    cin>>k;
    node T[4*n+1];
    build(T,a,0,n-1,1);
    
    ll tt;
    cin>>tt;
    while(tt--){
        ll c,d;
        cin>>c>>d;
        node t=query(T,0,n-1,c-1,d-1,1);
        cout<<t.my.size()<<" ";
        if(t.sz>t.my.size()/2){
            cout<<t.el<<endl;
        }
        else{
            cout<<"Champion"<<endl;
        }
    }

}