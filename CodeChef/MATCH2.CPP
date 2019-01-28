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
vi a,b;
int p;
int q,l,r,c;
int x,y,z;
int n,t;
int main()
{   ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        cin>>n>>q;
        a.resize(n);b.resize(n);
        REP(i,0,n){
            cin>>a[i];
        }
        REP(i,0,n){
            cin>>b[i];
        }
        p=0;
        for(int i=0; i<n;i++){
            if(a[i]==b[i]){
                p++;
            }
        }
        while(q--){
            cin>>x>>y>>z;
            l=x^p;
            r=y^p;
            c=z^p;
            for(int i=l-1;i<=(r-1);i++){
                if(a[i]==b[i]){
                    if(a[i]==c){

                    }
                    else{
                        p--;
                    }
                }
                else{
                    if(c==b[i]){
                        p++;
                    }
                }
                a[i]=c;
            }
            cout<<p<<"\n";
        }
    }
    return 0;
}