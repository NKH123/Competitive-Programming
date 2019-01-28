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

int main()
{   ios::sync_with_stdio(false);
   // freopen("a.in", "r", stdin);
    //freopen("b.in", "r", stdin);
    //freopen("c.in", "r", stdin);
    //freopen("d.in", "r", stdin);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        set<pair<ll,ll> >s;
       // set<pair<ll,ll>T;
        s.clear();
        //T.clear();
        while(n--){
            ll a,b;
            cin>>a>>b;
            //T.insert({a,b});
            s.insert({a+1,b+2});
            s.insert({a+1,b-2});
            s.insert({a-1,b+2});
            s.insert({a-1,b-2});
            s.insert({a+2,b+1});
            s.insert({a+2,b-1});
            s.insert({a-2,b+1});
            s.insert({a-2,b-1});
        }
        /*for(auto g:T){
            ll a=g.F;
            ll b=g.S;
            if(s.find({a,b})!=s.end()){
                s.insert()
            }
        }*/
        ll x,y;
        cin>>x>>y;
        ll a=x;
        ll b=y;
        int f=1;
        if(s.find({x,y})==s.end()){
            //cout<<"I'm here1\n";
            f=0;
        }
        else{
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    if(s.find({a+i,b+j})==s.end()){
                        //cout<<"i="<<i<<"j="<<j<<"\n";
                        //cout<<"I'm here2\n";
                        f=0;
                        break;
                    }
                }
            }
        }
        if(f==0){
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n";
        }

    }


    return 0;
}