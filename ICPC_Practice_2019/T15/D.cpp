#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define ll int
#define vd(T) vector<vector<T>>
#define mod (ll)(1e9+7)
#define pp(T) pair<T,T>
#define pb push_back
#define read1(x) scanf("%d",&x)
#define read2(x,y) scanf("%d%d",&x,&y)
#define read3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define read4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
#define mp make_pair
#define NN 200005
#define IO ios_base::sync_with_stdio(NULL),cin.tie(0),cout.tie(0)
#define loop(i,a,b) for(ll i=a;i<b;i++)


map<pair<pair<int,int>,pair<int,int>>,pair<int,pair<pair<int,int>,pair<int,int>>>> m;

pair<int,pair<pair<int,int>,pair<int,int>>> f(int a,int b,int c,int d){

    if((a*b)==(c*d)){
        return {0,{{a,b},{c,d}}};
    }
    if(m.count({{a,b},{c,d}})){
        return m[{{a,b},{c,d}}];
    }
    // cout<<a<<" "<<b<<" "<<c<< " "<<d<<endl;
    int A=a*b;
    int B=c*d;
    if(A>B){
        swap(a,c);
        swap(b,d);
    }

    pair<int,pair<pair<int,int>,pair<int,int>>> first1;
    first1.first=1e14;
    if(c%2==0){
        first1=f(a,b,c/2,d);
    }
    if(d%2==0){
        pair<int,pair<pair<int,int>,pair<int,int>>> t=f(a,b,c,d/2);
        if(t.first>first1.first)first1=t;
    }
    pair<int,pair<pair<int,int>,pair<int,int>>> second1;
    second1.first=1e14;
    if(d%3==0){
        second1=f(a,b,c,(d*2)/3);
    }
    if(c%3==0){
        pair<int,pair<pair<int,int>,pair<int,int>>> t=f(a,b,((2*c)/3),d);
        if(t.first>second1.first)second1=t;
    }
    pair<int,pair<pair<int,int>,pair<int,int>>> ans;
    if(ans.first==first1.first)ans=first1;
    else ans=second1;
    ans.first+=1;
    return m[{{a,b},{c,d}}]=ans;
}


signed main() {

    IO; 

    int a,b,c,d;
    cin>>a>>b>>c>>d;
    m.clear();
    pair<int,pair<pair<int,int>,pair<int,int>>> ans=f(a,b,c,d);
    if(ans.first>=100000){
        cout<<-1<<endl;
        return 0;
    }
    cout<<ans.first<<endl;
    
    cout<<ans.second.first.first<<" "<<ans.second.first.second<<endl;
    cout<<ans.second.second.first<<" "<<ans.second.second.second<<endl;

}


