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
    //freopen("a.in", "r", stdin);
    //freopen("b.in", "r", stdin);
    //freopen("c.in", "r", stdin);
    //freopen("d.in", "r", stdin);
    int t;
    cin>>t;
    vector<ll> a;
    vector<ll> b;
    stack<ll> s;
    while(t--){
        int n,m;
        cin>>n>>m;
        a.resize(n);
        b.resize(n);
        //s=stack<ll>();
        REP(i,0,n){
            //cout<<"i="<<i<<"\n";
            cin>>a[i];
            //cout<<"a[i]="<<a[i]<<"\n";
            if(!s.empty()){
                //int f=1;
                while(!s.empty()){
                int ind=s.top();
                if(a[ind]<=a[i]){
                    s.pop();
               //     cout<<"Popped "<<a[ind]<<"\n";
                }
                else{
                    //f=0;
                    break;
                }
            }
            //if(f==1)ut
            s.push(i);
           // cout<<"Pushed "<<a[i]<<"\n";
            }
            else{
                s.push(i);
             //   cout<<"Pushed "<<a[i]<<"\n";
            }
        }
        REP(i,0,n){
            cin>>b[i];
        }
        set<int>ss;
        ss.clear();
        //cout<<"The stack is\n";
        stack<ll>tt=s;
       /*while(!tt.empty()){
            int A=tt.top();
            tt.pop();
            //cout<<a[A]<<" ";
        }*/
       // cout<<"\n";
        while(!s.empty()){
            int a=s.top();
            s.pop();
            ss.insert(b[a]);
        }
        cout<<ss.size()<<"\n";

    }

    return 0;
}