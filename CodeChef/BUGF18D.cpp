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
ll t,n;
vector<pair<ll,ll> > a;
vector<pair<ll,ll> > b;
vector<ll> c;
vector<ll> temp;
ll merge_(vector<ll> &arr,vector<ll> &temp,ll l,ll mid,ll r){
    ll cnt=0;
    ll i=l;
    ll j=mid;
    ll k=l;
    while((i<=mid-1)&&(j<=r)){
        if(arr[i]<=arr[j]){
            temp[k]=arr[i];
            k++;
            i++;
        }
        else{
            temp[k]=arr[j];
            k++;
            j++;
            cnt=cnt+(mid-i);
        }
    }
    while(i<=mid-1){
        temp[k]=arr[i];
            k++;
            i++;
    }
    while(j<=r){
         temp[k]=arr[j];
            k++;
            j++;
    }
    for(int i=l;i<=r;i++){
        arr[i]=temp[i];
    }
    return cnt;
}
ll mergesort(vector<ll> &arr,vector<ll> &temp,ll l, ll r){
    ll cnt=0;
    if(r>l){
        int mid=(l+r)/2;
        cnt=mergesort(arr,temp,l,mid);
        cnt+=mergesort(arr,temp,mid+1,r);
        cnt+=merge_(arr,temp,l,mid+1,r);
    }
    return cnt;
}





int main()
{   ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        cin>>n;
        a.clear();
       // a.resize(n);
        REP(i,0,n){
            ll A;
            cin>>A;
            a.PB(make_pair(A,i+1));
        }
       /* cout<<"a is: ";
        REP(i,0,n){
        cout<<"{"<<a[i].F<<","<<a[i].S<<"} ";
        }
        cout<<"\n";*/
        b.clear();
        c.clear();
        b.resize(n);
        c.resize(n);
        REP(i,0,n){
        b[i].F=a[i].F;
        b[i].S=a[i].S;
        }
        sort(b.begin(),b.end());
        /*cout<<"b is: ";
        REP(i,0,n){
        cout<<"{"<<b[i].F<<","<<b[i].S<<"} ";
        }
        cout<<"\n";*/
        REP(i,0,n){
            c[i]=(b[i].F)*(abs(b[i].S-i-1));
        }
       /* cout<<"c is: ";
        for(auto g:c){
            cout<<g<<" ";
        }
        cout<<"\n";*/
        temp.clear();
        temp.resize(n);
        cout<<mergesort(c,temp,0,n-1)<<"\n";

    }

    return 0;
}
