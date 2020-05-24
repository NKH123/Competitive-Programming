#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vd(T) vector<vector<T>>
#define mod (ll)(1e9+7)
#define pp(T) pair<T,T>
#define pb push_back
#define endl "\n"
#define read1(x) scanf("%d",&x)
#define read2(x,y) scanf("%d%d",&x,&y)
#define read3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define read4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
#define mp make_pair
#define NN 200005
#define IO ios_base::sync_with_stdio(NULL),cin.tie(0),cout.tie(0)
#define loop(i,a,b) for(ll i=a;i<b;i++)
#define DEBUG cout<<"***********DEBUGGING***********"<<endl
#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; 
ll power(ll a,ll b){ if(b==0) return 1; ll s=power(a,b/2); s*=s;if(b&1) return s*a; return s;}
ll powermod(ll a,ll b,ll m){ if(b==0) return 1; ll s=power(a,b/2);s*=s; s%=m; if(b&1) return (s*a)%m; return s;}
inline int add(ll a,ll b,ll m=0){
    if(m==0) return a+b;
    return (a%m+b%m)%m;
}

inline int sub(ll a,ll b ,ll m=0){
    if(m==0) return a-b;
    return ((a%m-b%m)%m+m)%m;
}

inline int mul(ll a,ll b,ll m=0){
    if(m==0)return (a*b);
    return ((a%m)*(b%m))%m;
}

inline int div(ll a,ll b,ll m=0){
    if(m==0) return a/b;
    return ((a%m)*(powermod(a,b,m-2)%m))%m;
}



ll setup_k(ll *a,ll k){
  ordered_set x;
  // Now , insert and then check number of integers less than k by just using x.order_of_key(k+1)
  return 0;
}

void update(int *T,int si,int ei,int l,int c,int i){
  if(si>ei)return ;
  if(si==ei){
    T[i]=c;
    return ;
  }
  int mid=(si+ei)>>1;
  if(l<=mid){
    update(T,si,mid,l,c,2*i);
  }
  else{
    update(T,mid+1,ei,l,c,2*i+1);
  }
  T[i]=max(T[2*i],T[2*i+1]);
}

bool cmp(pair<pp(int),int> a,pair<pp(int),int> b){
  if(a.first.second==b.first.second){
    if(a.first.first==b.first.first)
      return a.second>b.second;
    return a.first.first>b.first.first;
  }
  return a.first.second<b.first.second;
}

int query(int *T,int si,int ei,int l,int r,int i){
  if(si>ei || si>r || ei<l){
    return 0;
  }
  if(si>=l && ei<=r){
    return T[i];
  }
  int mid=(si+ei)>>1;
  return max(query(T,si,mid,l,r,2*i),query(T,mid+1,ei,l,r,2*i+1));
}

int main() {

    IO; 

    int n;
    cin>>n;
    vector<pair<pair<int,int>,int>> v(n);
    for(int i=0;i<n;i++){
      cin>>v[i].first.first>>v[i].first.second>>v[i].second;
    }

    sort(v.begin(),v.end(),cmp);

    int T[4*n+1]{0};
    update(T,0,n-1,0,v[0].second,1);
    int ans=v[0].second;
    for(int i=1;i<n;i++){
      int c=0;
      int ind=i;
      int si=0,ei=i-1;
      while(si<=ei){
        int mid=(si+ei)>>1;
        if(v[mid].first.second>v[i].first.first){
          ind=mid;
          ei=mid-1;
        }
        else{
          si=mid+1;
        }
      }
      c=v[i].second+query(T,0,n-1,ind,i-1,1);
      update(T,0,n-1,i,c,1);
      ans=max(ans,c);
    }
    for(int i=0;i<n;i++){
        cout<<T[i]<<" ";
    }
    cout<<"\n";
    cout<<ans<<endl;
        

}


